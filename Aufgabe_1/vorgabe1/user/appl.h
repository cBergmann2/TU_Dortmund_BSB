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


#include "thread/entrant.h"
#include "thread/scheduler.h"

#include "device/cgastr.h"
#include "device/keyboard.h"

#include "machine/cpu.h"

#include "guard/secure.h"



class Application : public Entrant
 
 {
private:
    Application (const Application &copy); // Verhindere Kopieren
	
	Entrant* loopPtr;

public:
/* Hier muesst ihr selbst Code vervollstaendigen */                 
    Application(void* tos) : 
		Entrant(tos)
	{
	}
    
	void setKillEntrant(Entrant* loop)
	{
		this->loopPtr = loop;
	}

	void action ();
 };

#endif
