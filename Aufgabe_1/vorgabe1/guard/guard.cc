/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                G U A R D                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe dieser Klasse koennen Aktivitaeten, die einen kritischen        */
/* Abschnitt betreffen, der mit einem Guard-Objekt geschuetzt ist, mit       */
/* Unterbrechungsbehandlungsroutinen synchronisiert werden, die ebenfalls    */
/* auf den kritischen Abschnitt zugreifen.                                   */
/*****************************************************************************/

#include "guard/guard.h"

Guard::Guard () : 
  Locker()
{
  
}

/**
  * Mit dieser Methode wird der kritische Abschnitt verlassen und 
  * die angestauten Epiloge werden abgearbeitet.
  */
void Guard::leave ()
{
	CPU cpu;
	
	//Kurzfristiges Entkoppeln der Prologue-Funktion
	//In Prologue kann enqueue aufgerufen werden
	cpu.disable_int();
	Gate* item = (Gate*)gates.dequeue();
	
	
	//Alle Epiloge ausführen
	while(item){
		item->queued(false);
		
		//Freigabe für Prologues 
		cpu.enable_int();
		item->epilogue();

		//Interrupts sperren für sichere Abfrage
		cpu.disable_int();
		item = (Gate*)gates.dequeue();
	}
	
	//Bereich freigeben
	this->retne();
	
	cpu.enable_int();
	//Eingetroffene Interrupts werden bearbeitet, da 
	// locker::available = true
}
  
/**
  * Diese Methode wird von guardian () aufgerufen, falls der zuvor 
  * ausgeführte Prolog durch einen Rückgabewert true angezeigt hat, 
  * dass sein Epilog ausgeführt werden soll. Ob der Epilog sofort 
  * behandelt oder zunächst nur in die Epilogliste eingehängt wird, 
  * hängt davon ab, ob der kritische Abschnitt frei oder besetzt ist.   
  */   
void Guard::relay (Gate* item)
{
	CPU cpu;
	
	if(avail())
	{
		enter();
		cpu.enable_int();
		item->epilogue();	//Epilog ausführen		
		leave();
	}else{
		if(!item->queued())
		{
			gates.enqueue((Chain*)item);	
			item->queued(true);
		}
	}
}