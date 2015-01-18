/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 B E L L                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Eine "Glocke" ist eine abstrakte Basisklasse, die das Ausloesen einer     */
/* Aktivitaet nach einer bestimmten Wartezeit erlaubt.                       */
/* Dazu besitzt sie einen Zaehler, der vom "Gloeckner" (Bellringer) ver-     */
/* waltet wird.                                                              */
/*																			 */
/* Hinweise																	 */
/* Um Bell verwenden zu können, muss eine abgeleitete Klasse erstellt werden */
/* in der die Methode ring() definiert wird.								 */
/*																			 */
/*	Alle anderen Methoden werden am besten inline definiert. 				 */
/*****************************************************************************/

#ifndef __Bell_include__
#define __Bell_include__

#include "object/chain.h"


class Bell : public Chain 
 {
private:
    Bell(const Bell &copy); // Verhindere Kopieren
public:
    Bell() {}

	void wait (int value)
	{
	
	}
	
	/**
	 * Setzen bzw. Abfragen des Zählers.
	 */
	int wait ()
	{
	
	}
	
	/**
	 * Dekremementiert den Zähler.
	 */
	void tick ()
	{
	
	}
		
	/**
	 * Liefert true, wenn die Zeit abgelaufen ist.
	 */
	bool run_down()
	{
	
	}
		
		
	/**
	 * Wird vom Glöckner aufgerufen, wenn es an der Zeit ist. 
	 */
	virtual void ring () = 0;
		

};

#endif
