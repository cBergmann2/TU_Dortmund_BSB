/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              P L U G B O X                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Abstraktion einer Interruptvektortabelle. Damit kann man die Adresse der  */
/* Behandlungsroutine fuer jeden Hardware-, Softwareinterrupt und jede       */
/* Prozessorexception festlegen.                                             */
/*****************************************************************************/

#ifndef __Plugbox_include__
#define __Plugbox_include__

#include "guard/gate.h"
#include "device/panic.h"

class Plugbox
 {
public:
	const int timer = 32;			//Interrupt-Nummer des Timer Bausteins
	const int keyboard = 33;		//Interrupt-Nummer der Tastatur

	Plugbox();
	void assign(unsigned int slot, Gate& gate);
	Gate& report(unsigned int slot);

private:
    Plugbox(const Plugbox &copy); 	// Verhindere Kopieren
    Gate* interruptTabelle[64];		//Interrupt-Vektor-Tabelle
 };

#endif
