/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

/* INCLUDES */

#include "user/appl.h"
#include "device/keyboard.h"
         
/* GLOBALE VARIABLEN */
extern CGA_Stream kout;
extern Guarded_Organizer scheduler;
extern Keyboard board;

void Application::action ()
{
	kout << "START";

	while(1)
	{
		kout << board.getkey().ascii();

		kout.flush();
	}
}
