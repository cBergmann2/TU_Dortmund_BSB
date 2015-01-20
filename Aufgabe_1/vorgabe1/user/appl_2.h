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
#include "syscall/guarded_organizer.h"

#include "device/cgastr.h"
#include "device/keyboard.h"

#include "machine/cpu.h"

#include "guard/secure.h"
#include "syscall/guarded_buzzer.h"


/**
* Die Klasse Application stellt die Anwendung des Betriebssystems dar. Sie
* wird in Form eines eigenen Fadens ausgeführt und braucht dementsprechend
* auch einen eigenen Stack.
*/
class Application_2 : public Thread

{
private:
	Application_2(const Application &copy); // Verhindere Kopieren

	Thread* loopPtr;

public:
	/* Hier muesst ihr selbst Code vervollstaendigen */
	Application(void* tos) :
		Thread(tos)
	{
	}

	void setKillEntrant(Thread* loop)
	{
		this->loopPtr = loop;
	}

	void action();
};

#endif
