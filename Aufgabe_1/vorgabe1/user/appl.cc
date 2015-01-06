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
extern Guarded_Scheduler scheduler;


void Application::action ()
{
	CPU cpu;
	int wait=0;
	Keyboard board;

	//Initialisierungen
	kout.setpos(0,0);
	board.plugin();

	cpu.enable_int();

	//resume	
	kout << "Appl: Pause";
	kout.flush();
	wait=1000000000;
	while(wait) wait--;

	//nochmal resume
	kout << endl << "Appl: Pause";
	kout.flush();
	wait=1000000000;
	while(wait) wait--;
	
    //nochmal resume
	kout << endl << "Appl: Pause";
	kout.flush();
	wait=1000000000;
	while(wait) wait--;

	//Kill
	kout << "\nAppl: Loop wird abgeschossen mit kill";
	kout.flush();
	scheduler.kill(*loopPtr);
	
	//resume	
	kout << endl << "Appl: Pause";
	kout.flush();
	wait=1000000000;
	while(wait) wait--;

	//Exit
	kout << endl << "Appl: Terminierung";
	kout.flush();
	
	wait=1000000000;
	while(wait) wait--;

	scheduler.exit();

	//Ausgabe wenn fehlerhaft
	kout << endl << "Appl: Ausgabe trotz Terminierung!";

}
