/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         G U A R D E D _ B U Z Z E R                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Schnittstelle von Anwendungsthreads zu Buzzer-Objekten.                   */
/*****************************************************************************/

#ifndef __Guarded_Buzzer_include__
#define __Guarded_Buzzer_include__

#include "meeting/buzzer.h"

class Guarded_Buzzer : public Buzzer
{
private:
    Guarded_Buzzer(const Guarded_Buzzer &copy); // Verhindere Kopieren
public:
    Guarded_Buzzer() {}

	/**
	 * Die Klasse Guarded_Buzzer implementiert die Systemaufrufschnittstelle 
	 * zur Buzzer Klasse. Die von Guarded_Buzzer angebotenen Methoden 
	 * werden direkt auf die Methoden der Basisklasse abgebildet, nur dass 
	 * ihre Ausführung jeweils mit Hilfe eines Objekts der Klasse Secure 
	 * geschützt wird. 
	 */
	//virtual ~Buzzer();	// virtual ~Guarded_Buzzer();
	void set (int ms);
	void sleep ();
};

#endif
