/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              G U A R D I A N                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Zentrale Unterbrechungsbehandlungsroutine des Systems.                    */
/* Der Parameter gibt die Nummer des aufgetretenen Interrupts an.            */
/*****************************************************************************/

/* INCLUDES */
#include "machine/plugbox.h"
#include "guard/guard.h"

/* FUNKTIONEN */

extern "C" void guardian (unsigned int slot);


/* GUARDIAN: Low-Level Interrupt-Behandlung. Die Funktion wird spaeter noch */
/*           erweitert.                                                     */

extern Guard guard;
extern Plugbox plugbox;

/**
 * Die Funktion guardian ist für die gerätespezifische Unterbrechungsbehandlung 
 * zuständig. Dazu wird mit Hilfe der Unterbrechungsnummer in dem globalen 
 * Plugbox Objekt plugbox das zuständige Gate Objekt ermittelt und dessen 
 * prologue() Methode ausgeführt. Gegebenenfalls wird auch ein Epilog angefordert. 
 */
void guardian (unsigned int slot)
{
    if(plugbox.report(slot).prologue())
	{
		//Epilog einreihen
		guard.relay(&plugbox.report(slot));
	}    
} 
