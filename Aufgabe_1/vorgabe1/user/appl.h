/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

#ifndef __application_include__
#define __application_include__


#include "syscall/thread.h"
#include "syscall/guarded_organizer.h"

#include "device/cgastr.h"


#include "machine/cpu.h"

#include "guard/secure.h"

/**
 * Die Klasse Application stellt die Anwendung des Betriebssystems dar. Sie 
 * wird in Form eines eigenen Fadens ausgeführt und braucht dementsprechend 
 * auch einen eigenen Stack.
 */
class Application : public Thread
 
{
private:
    Application (const Application &copy); // Verhindere Kopieren
	
	
public:
/* Hier muesst ihr selbst Code vervollstaendigen */                 
	
	Application(void* tos) : 
		Thread(tos)
	{
	}

	void action ();
 };

#endif
