/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

#ifndef __application_2_include__
#define __application_2_include__

#include "syscall/thread.h"
#include "device/cgastr.h"
#include "syscall/guarded_buzzer.h"

/**
* Die Klasse Application stellt die Anwendung des Betriebssystems dar. Sie
* wird in Form eines eigenen Fadens ausgeführt und braucht dementsprechend
* auch einen eigenen Stack.
*/
class Application2 : public Thread
{
private:
	Application2(const Application2 &copy); // Verhindere Kopieren

public:
	/* Hier muesst ihr selbst Code vervollstaendigen */
	Application2(void* tos);
	
	virtual ~Application2(){}

	void action();
};

#endif
