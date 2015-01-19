/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                    G U A R D E D _ O R G A N I Z E R                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zum Organizer.                                  */
/*****************************************************************************/

#include "syscall/guarded_organizer.h"

/**
 * Mit dieser Methode wird der Prozess that beim Scheduler angemeldet.
 */
void Guarded_Organizer::ready (Thread& that)
{
	Secure section;
	Organizer::ready(that);
}

/**
 * Hiermit kann sich ein Prozess selbst beenden.
 */
void Guarded_Organizer::exit ()
{
	Secure section;
	Organizer::exit();
}
	
/**
 * Mit dieser Methode kann ein Prozess einen anderen (that) beenden.
 */
void Guarded_Organizer::kill (Thread& that)
{
	Secure section;
	Organizer::kill(that);
}
	
/**
 * Hiermit kann ein Prozesswechsel ausgelöst werden.
 */
void Guarded_Organizer::resume ()
{
	Secure section;
	Organizer::resume();	
}