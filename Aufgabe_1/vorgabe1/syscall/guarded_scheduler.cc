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
{

}

/**
 * Mit dieser Methode wird der Prozess that beim Scheduler angemeldet.
 */
void Guarded_Scheduler::ready (Thread& that)
{

}

/**
 * Hiermit kann sich ein Prozess selbst beenden.	
 */
void Guarded_Scheduler::exit ()
{

}

/**
 * Mit dieser Methode kann ein Prozess einen anderen (that) beenden.
 */
void Guarded_Scheduler::kill (Thread& that)
{

}

/**
 *	Hiermit kann ein Prozesswechsel ausgelöst werden. 
 */
void Guarded_Scheduler::resume ()
{

}
