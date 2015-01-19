/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                   G U A R D E D _ K E Y B O A R D                         */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zur Tastatur.                                   */
/*****************************************************************************/

#include "syscall/guarded_keyboard.h"

/**
 * Diese Methode entspricht der gleichnamigen Methode der Basisklasse 
 * Keyboard, nur dass sie mit Hilfe eines Secure Objekts geschützt wird. 
 */
Key Guarded_Keyboard::getkey ()
{
	Secure section;
	Guraded_Keyboard::getkey();
}