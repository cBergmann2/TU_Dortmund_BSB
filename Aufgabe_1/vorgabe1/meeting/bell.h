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
	int zaehler;
	
public:
    Bell() {}

	inline void wait (int value)
	{
		this->zaehler=value;
	}
	
	/**
	 * Setzen bzw. Abfragen des Zählers.
	 */
	inline int wait ()
	{
		return this->zaehler;
	}
	
	/**
	 * Dekremementiert den Zähler.
	 */
	inline void tick ()
	{
		this->zaehler--;
	}
		
	/**
	 * Liefert true, wenn die Zeit abgelaufen ist.
	 */
	inline bool run_down()
	{
		if(this->zaehler==0) return true;
	}
		
		
	/**
	 * Wird vom Glöckner aufgerufen, wenn es an der Zeit ist. 
	 */
	virtual void ring () = 0;
		

};

#endif
