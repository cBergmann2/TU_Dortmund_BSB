/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                    G U A R D E D _ S C H E D U L E R                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zum Scheduler.                                  */
/*****************************************************************************/


#include "syscall/guarded_scheduler.h"

Guarded_Scheduler::Guarded_Scheduler()
{}

/**
 * Mit dieser Methode wird der Prozess that beim Scheduler angemeldet.
 */
void Guarded_Scheduler::ready (Thread& that)
{
	Secure section; //Schutz bis zum verlassen der Funktion (Destruktoraufruf von section)

	Scheduler::ready((Entrant&) that); //cast evtl. ueberdenken?
}

/**
 * Hiermit kann sich ein Prozess selbst beenden.	
 */
void Guarded_Scheduler::exit ()
{
	Secure section;
	
	Scheduler::exit();
}

/**
 * Mit dieser Methode kann ein Prozess einen anderen (that) beenden.
 */
void Guarded_Scheduler::kill (Thread& that)
{
	Secure section;
	
	Scheduler::kill((Entrant&) that); //cast evtl. ueberdenken?
}

/**
 *	Hiermit kann ein Prozesswechsel ausgelöst werden. 
 */
void Guarded_Scheduler::resume ()
{
	Secure section;
	
	Scheduler::resume();
}
