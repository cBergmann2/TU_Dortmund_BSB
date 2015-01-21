/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 A P P L 2                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*****************************************************************************/

#ifndef __appl2_include__
#define __appl2_include__

#include "syscall/thread.h"
#include "device/cgastr.h"
#include "syscall/guarded_organizer.h"
#include "syscall/guarded_buzzer.h"

extern Guarded_Organizer scheduler;
extern CGA_Stream kout;

class Appl_2 : public Thread
{

public:
	Appl_2(void* tos) : 
		Thread(tos)
	{ }
		
	void registerBuzzer(Guarded_Buzzer* item, bool master)
	{
		this->buzzer = item;
		this->master = master;
	}
		
	/**
	 * Abgeänderte Funktionalität:
	 * Gibt eine Ausgabe auf der Konsole aus und gibt die CPU wieder ab.
	 */
	void action()
	{
		int i = 5;
		
		while (i--)
		{
			
			if(master)	
			{
				buzzer->set(2000);
				kout << "master wird schlafengelegt" << endl;
			}else {
				kout << "NICHT-master wird schlafengelegt" << endl;
			}
			buzzer->sleep();
			
		}
	}
	
private:
	Guarded_Buzzer *buzzer;
	bool master;
};
 
#endif
