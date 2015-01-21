/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

#ifndef __neuApp_include__
#define __neuApp_include__


#include "syscall/thread.h"
#include "syscall/guarded_buzzer.h"
#include "device/cgastr.h"
#include "syscall/guarded_organizer.h"

extern CGA_Stream kout;
extern Guarded_Organizer scheduler;

/**
 * Die Klasse Application stellt die Anwendung des Betriebssystems dar. Sie 
 * wird in Form eines eigenen Fadens ausgeführt und braucht dementsprechend 
 * auch einen eigenen Stack.
 */
class NeuApp : public Thread
{
private:
    NeuApp (const NeuApp &copy); // Verhindere Kopieren
	
	
public:
/* Hier muesst ihr selbst Code vervollstaendigen */                 
	
	NeuApp(void* tos) : 
		Thread(tos)
	{
	}

	virtual void action ()
	{
		int i = 20;
		Guarded_Buzzer buzzer;
		
		while (i--)
		{
			kout << endl << "------------------------------------" << endl;
			kout.flush();
			buzzer.set(1000);
			buzzer.sleep();
		}
		
	}
};

#endif
