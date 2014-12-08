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
extern Scheduler scheduler;


void Application::action ()
{
	CPU cpu;
	int wait=0;
	Keyboard board;

	//Initialisierungen
	kout.setpos(0,0);
	board.plugin();

	cpu.enable_int();


	//Warten
	wait = 0;
	while(wait++ < 0x100000);
	
	//resume	
	kout << "Appl: Resume wird aufgerufen";
	kout.flush();
	scheduler.resume();	//Loop wird ausgeführt
		
	//Warten
	wait = 0;
	while(wait++ < 0x100000);	
	
	//Kill
	kout << "\nAppl: Loop wird abgeschossen";
	kout.flush();
	scheduler.kill(*loopPtr);

	//Warten
	wait = 0;
	while(wait++ < 0x100000);	

	//resume	
	kout << endl << "Appl: Resume wird erneut aufgerufen";
	kout.flush();
	scheduler.resume();	//Loop wird nicht ausgeführt
		
	//Warten
	wait = 0;
	while(wait++ < 0x100000);

	//Exit
	kout << endl << "Appl: Terminierung";
	kout.flush();
	scheduler.exit();

	//Ausgabe wenn fehlerhaft
	kout << endl << "Appl: Ausgabe trotz Terminierung!";

}
