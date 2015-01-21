/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                           S E M A P H O R E                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Semaphore werden zur Synchronisation von Threads verwendet.               */
/*****************************************************************************/

#include "meeting/semaphore.h"



extern Guarded_Organizer scheduler;

//Der Konstruktor initialisiert den Semaphorzähler mit dem angegebenen Wert c
Semaphore::Semaphore(int c)
{
	count = c;
}

//Warteoperation: Sofern der Semaphorzähler größer als Null ist, wird er nur um eins erniedrigt. 
//Anderenfalls wird der aktuell laufende Prozess (ein Customer Objekt) an die Warteliste angefügt und blockiert.
void Semaphore::p()
{
	Customer *active;
	
	if(--count<0)
	{
		active = (Customer*)(scheduler.active());
		scheduler.block(*active, *this);
	}
}

//Freigabeoperation: Wenn auf der Warteliste mindestens ein Customer eingetragen ist, 
//wird der erste davon aufgeweckt. Anderenfalls wird der Semaphorzähler um eins erhöht.
void Semaphore::v()
{
	Customer *next;
	if(++count<=0)
	{
		next = (Customer*)this->dequeue();
		
		if(!next) return;	//FEHLERFALL
		
		next->waiting_in(NULL);
		scheduler.Scheduler::ready(*next);	//Customer zurück in die Readyliste einfügen
	}
}
