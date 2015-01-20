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
	char ascii;

	kout << "START vertauschte Tastenbelegung";
	kout.flush();

	while(1)
	{
		ascii = board.getkey().ascii();
		
		if (ascii == '1') kout << '9';
		if (ascii == '2') kout << '8';
		if (ascii == '3') kout << '7';
		if (ascii == '4') kout << '6';
		if (ascii == '5') kout << '5';
		if (ascii == '6') kout << '4';
		if (ascii == '7') kout << '3';
		if (ascii == '8') kout << '2';
		if (ascii == '9') kout << '1';

		kout.flush();
	}
}
