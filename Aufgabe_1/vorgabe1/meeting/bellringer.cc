/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          B E L L R I N G E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Der "Gloeckner" wird im Rahmen der Timer-Epilog Bearbeitung aktiviert.    */
/* Er prueft, ob irgendwelche Glocken (Bell-Objekte) laeuten muessen. Die    */
/* Glocken befinden sich in einer Queue, die der Gloeckner verwaltet.        */
/*****************************************************************************/

#include "meeting/bellringer.h"


/**
 * Prüft, ob Glocken zu läuten sind und tut es gegebenenfalls.
 */
void Bellringer::check ()
{
	//Immer nur estes Element in der Liste dekrementieren
	Bell *bell;

	bell=(Bell*)first(); //erstes Element holen
	if(!bell) return;

	bell->tick(); //Dekrementiere
	if(bell->run_down()==true)
	{
		dequeue();	//aus liste entfernen (ist immer erstes element in der liste)
		bell->ring();
	}
}

/**
 * Die Glocke bell wird dem Glöckner überantwortet. Sie soll nach ticks Zeiteinheiten geläutet werden.
 */
void Bellringer::job (Bell *bell, int ticks)
{
	Bell *tempBell;
	Bell *oldBell;
	int ticksKumuliert=0;

	tempBell= (Bell*)first(); //erstes Element holen
	if(tempBell!=0) //liste schon besetzt
	{
		if(ticks<tempBell->wait()) //neues Bell Element hat geringste Anzahl Ticks
		{
			tempBell->wait(tempBell->wait()-ticks);	//zaehler von altem ersten Element der Liste anpassen
			bell->wait(ticks);
			insert_first(bell);
		}
		else //neues Bell Element hat weniger Ticks als erstes Element in Liste
		{
			
			while(tempBell->next!=0)//Bis zum letzten Element der Liste
			{
				oldBell=tempBell;
				tempBell = (Bell*) tempBell->next;
				ticksKumuliert+=oldBell->wait();

				if(ticks<tempBell->wait()+ticksKumuliert) //neues Bell Element hat geringere Anzal Ticks als aktuelles
				{
					bell->wait(ticks-ticksKumuliert);
					tempBell->wait(tempBell->wait()-(ticks-ticksKumuliert)); //Ticks von aktuellem Element neu berechnen
					insert_after(oldBell, bell); //neues Bell Element vor aktuelles einsetzen
					return;
				}
					
			}

			//Wenn hier angekommen: neue Bell hat mehr Ticks als alle Elemente in der Liste
			bell->wait(ticks-tempBell->wait());
			enqueue(bell);		//neue Bell hinten anhängen
		}
		
	}
	else //liste leer
	{
		bell->wait(ticks);
		enqueue(bell);
	}

}
	
	
/**
 * Die Glocke bell soll nun doch nicht geläutet werden. 
 */
void Bellringer::cancel (Bell *bell)
{
	remove(bell);
}
