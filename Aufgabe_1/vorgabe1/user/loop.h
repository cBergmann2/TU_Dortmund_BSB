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

#include "thread/entrant.h"
#include "device/cgastr.h"

CGA_Stream kout;

class Loop : public Entrant
{

public:
	Loop(void* tos) : 
		Entrant(tos)
	{
		
	}
	
	Loop(void* tos, char a, Loop* partner):
		Entrant(tos)
	{
		this->a = a;
		this->partner = partner;
	}
	
	void setter(char a, Loop* partner)
	{
		this->a = a;
		this->partner = partner;
	}
	
	void action()
	{
		kout << a;
		kout.flush();
		resume(*partner);
		
		kout << " ENDE " ;
		while(1);
	}
	
private:
	char a;
	Loop* partner;
};
 
#endif
