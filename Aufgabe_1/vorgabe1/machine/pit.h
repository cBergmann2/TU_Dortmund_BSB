/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

#ifndef __pit_include__
#define __pit_include__

#include "machine/io_port.h"

/**
 * Die Klasse PIT steuert den Programmable Interval Timer (PIT) des PCs.
 */
class PIT
 {
private:
    PIT(const PIT &copy); // Verhindere Kopieren

	int us;
	IO_PORT ctrlRegister;
	IO_PORT counter1;
public:
	
	/**
	 * Im Konstruktor wird der Timer so initialisiert, dass er in Abständen 
	 * von ca. us Mikrosekunden regelmäßig Unterbrechungen auslöst. Da die 
	 * Auflösung des Timerbausteins maximal 838 Nanosekunden beträgt, ist 
	 * keine ganz exakte Einstellung im Mikrosekundenbereich möglich.
	 */
    PIT (int us) :
		ctrlRegister(0x43),
		counter1(0x40);
	{
		interval (us);
    }
    
    /**
	 * Gibt an, welches Unterbrechungsintervall eingestellt wurde.
	 */
    int interval ();
	
	/**
	 * Stellt das Unterbrechungsintervall neu ein.
	 */
    void interval (int us);
};

#endif
