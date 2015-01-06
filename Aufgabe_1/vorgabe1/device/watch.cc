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
extern Guarded_Scheduler scheduler;

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
	//Prozesswechsel herbeiführen
	scheduler.Scheduler::resume();
}

