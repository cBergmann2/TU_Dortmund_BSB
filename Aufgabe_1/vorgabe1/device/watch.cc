/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              W A T C H                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/*****************************************************************************/

#include "device/watch.h"

extern Plugbox plugbox;
extern Guarded_Organizer scheduler;
extern Bellringer bellringer;

// WINDUP: "zieht die Uhr auf". Danach laeuft sie los und loest in
//         regelmaessigen Abstaenden Unterbrechungen aus.
void Watch::windup ()
{
	PIC pic;
	plugbox.assign(plugbox.timer, *this);	//bei plugbox anmelden
	pic.allow (0);	//interrupts vom timer zulassen
}

// PROLOGUE: Prologue der Uhrenunterbrechung
bool Watch::prologue ()
{
	return true;
}

// EPILOGUE: Epilogue der Uhrenunterbrechung
void Watch::epilogue ()
{
	static int times=5;
	
	bellringer.check();
	scheduler.resume();
	
	/*if((--times) == 0){
		scheduler.resume();	//alle 10 ms
		times=5;
	}*/
}

