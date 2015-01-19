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
         
/* GLOBALE VARIABLEN */
extern CGA_Stream kout;
extern Guarded_Organizer scheduler;


void Application::action ()
{
	Keyboard board;

	//Initialisierungen
	kout.setpos(0,0);
	board.plugin();
	
	kout << "START";

	while(1)
	{
		kout << board.getkey().ascii();
	}
}
