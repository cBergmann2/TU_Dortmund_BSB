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

#include "user/appl_2.h"


/* GLOBALE VARIABLEN */
extern CGA_Stream kout;
extern Guarded_Organizer scheduler;


void Application_2::action()
{
	char ascii;
	Guarded_Buzzer buzzer;

	while (1)
	{
		kout << endl;
		buzzer.set(1000);
		buzzer.sleep;

	}
}
