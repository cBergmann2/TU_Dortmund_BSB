/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 L O O P                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Loop ist ein Thread, der nichts weiter tut als einen Zaehler hochzu-      */
/* zaehlen und dies auf dem Bildschirm anzuzeigen. Zwischendurch gibt er     */
/* den Prozessor ab.                                                         */
/*****************************************************************************/

#ifndef __loop_include__
#define __loop_include__

#include "syscall/thread.h"
#include "device/cgastr.h"
#include "syscall/guarded_organizer.h"

extern Guarded_Organizer scheduler;
extern CGA_Stream kout;

class Loop : public Thread
{

public:
	Loop(void* tos) : 
		Thread(tos)
	{ }
		
	/**
	 * Abgeänderte Funktionalität:
	 * Gibt eine Ausgabe auf der Konsole aus und gibt die CPU wieder ab.
	 */
	void action();
	
private:

};
 
#endif
