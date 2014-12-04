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

#ifndef __loop2_include__
#define __loop2_include__

#include "thread/entrant.h"
#include "device/cgastr.h"
#include "thread/scheduler.h"

extern Scheduler scheduler;
extern CGA_Stream kout;

class Loop2 : public Entrant
{

public:
	Loop2(void* tos) : 
		Entrant(tos)
	{
		
	}
	
	Loop2(void* tos, char a):
		Entrant(tos)
	{
		this->a = a;
	}
	
	
	void action()
	{
		kout << a;
		kout.flush();
		scheduler.resume();
		
		kout << a << " ENDE " ;
		kout.flush();
		scheduler.resume();
		while(1);
	}
	
private:
	char a;
};
 
#endif
