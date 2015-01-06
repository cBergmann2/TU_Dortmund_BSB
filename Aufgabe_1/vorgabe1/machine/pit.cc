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
int PIT::interval ()
{
	return this->us;
}

/**
* Stellt das Unterbrechungsintervall neu ein.
*/
void PIT::interval (int us)
{
	unsigned short value;
	unsigned int temp;
	this->us = us;
	
	//value berechnen
	//auf 838 Nanosekunden normieren
	// 107 / 128 = 0.8359
	if(us > 54921)
	{
		//Ausserhalb des Zählbereichs
		return;
	}
	
	temp = us<<7;		//*128
	temp = temp/107;
	temp = temp - ( ( us*3 ) / 1000 );
	value = (unsigned short)temp;
	
	//Steuerregister beschreiben
	//  00 Zähler 0
	//  11 niederwertiges, anschließend höherwertiges Zählerbyte
	// 010 Modus2 -> continuous countdown
	//   0 binäre Zählung
	ctrlRegister.outb(0x34);
	
	counter1.outb((char)value);
	counter1.outb((char)(value>>8));
}
