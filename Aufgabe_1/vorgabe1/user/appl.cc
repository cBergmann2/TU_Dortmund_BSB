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
	kout << "Appl: Resume wird aufgerufen";
	kout.flush();
	wait=10000000;
	while(wait) wait--;

	//nochmal resume
	kout << endl << "Appl: Resume wird nochmal aufgerufen";
	kout.flush();
	wait=10000000;
	while(wait) wait--;
	
    //nochmal resume
	kout << endl << "Appl: Resume wird nochmal aufgerufen";
	kout.flush();
	wait=10000000;
	while(wait) wait--;

	//Kill
	kout << "\nAppl: Loop wird abgeschossen mit kill";
	kout.flush();
	scheduler.kill(*loopPtr);
	wait=10000000;
	while(wait) wait--;
	
	//resume	
	kout << endl << "Appl: Resume wird erneut aufgerufen";
	kout.flush();
	wait=10000000;
	while(wait) wait--;

	//Exit
	kout << endl << "Appl: Terminierung";
	kout.flush();
	
	wait=10000000;
	while(wait) wait--;

	scheduler.exit();

	//Ausgabe wenn fehlerhaft
	kout << endl << "Appl: Ausgabe trotz Terminierung!";

}
