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
extern PIC pic;

// WINDUP: "zieht die Uhr auf". Danach laeuft sie los und loest in
//         regelmaessigen Abstaenden Unterbrechungen aus.
void Watch::windup ()
{
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
	guardedScheduler->resume();
}