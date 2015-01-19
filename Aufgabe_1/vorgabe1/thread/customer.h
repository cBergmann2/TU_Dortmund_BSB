/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         C U S T O M E R                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Ein Thread, der auf ein Ereignis warten kann.                             */
/*****************************************************************************/

#ifndef __customer_include__
#define __customer_include__

#include "thread/entrant.h"
#include "meeting/waitingroom.h"
#include "device/cgastr.h"

#define NULL 0

extern CGA_Stream kout;
  
class Customer : public Entrant    
{
private:
    Customer (const Customer &copy); // Verhindere Kopieren
	Waitingroom* act_waitingroom;
	
public:
	/**
	 * Der Konstruktor leitet den Parameter tos an den Konstruktor 
	 * der Basisklasse Entrant weiter.
	 */
	Customer (void* tos) : 
		Entrant ( tos )
	{
		act_waitingroom = NULL;
	}
		
	/**
	 * Mit dieser Methode wird im Customer vermerkt, dass dieser derzeit 
	 * im Waitingroom w auf ein Ereignis wartet.
	 */
	void waiting_in (Waitingroom *w)
	{
		if((w != NULL) && (act_waitingroom != NULL))
		{
			kout << endl << "act_waitingroom != null";
			kout.flush();
			return;
		}
		
		act_waitingroom = w;
	}
	
	/**
	 * Hiermit kann abgefragt werden, in welchem Waitingroom Objekt der 
	 * Customer eingetragen ist. Ein Rückgabewert von 0 soll bedeuten, dass 
	 * der Prozess auf überhaupt kein Ereignis wartet, also entweder der 
	 * aktuell laufende Prozess ist, auf der Ready-Liste des Schedulers steht, 
	 * bereits terminiert ist oder noch gar nicht beim Scheduler angemeldet wurde. 
	 */
	Waitingroom* waiting_in ()
	{
		return act_waitingroom;
	}
    
};

#endif