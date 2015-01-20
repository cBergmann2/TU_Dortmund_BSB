/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                   INIT- A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

#ifndef __init_include__
#define __init_include__


#include "syscall/thread.h"


/**
 * 
 */
class Init : public Thread
 
{
private:
    Init (const Init &copy); // Verhindere Kopieren

public:
           
    Init(void* tos) : 
		Thread(tos)
	{
	}

	void action ();
};

#endif
