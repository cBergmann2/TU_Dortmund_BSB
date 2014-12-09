/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

#include "machine/pit.h"



/**
* Gibt an, welches Unterbrechungsintervall eingestellt wurde.
*/
int interval ()
{
	return this->us;
}

/**
* Stellt das Unterbrechungsintervall neu ein.
*/
void interval (int us)
{
	short value;
	long long temp;
	this->us = us;
	
	//value berechnen
	//auf 838 Nanosekunden normieren
	//
	temp = us<<5;
	value = (temp/38) + 1;

	
	//Steuerregister beschreiben
	//  00 Zähler 0
	//  11 niederwertiges, anschließend höherwertiges Zählerbyte
	// 010 Modus2 -> continuous countdown
	//   0 binäre Zählung
	ctrlRegister.outb(0x34);
	
	counter1.outb((char)value);
	counter1.outb((char)(value>>8));
}