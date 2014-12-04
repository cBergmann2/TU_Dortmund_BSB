/* $Id: coroutine.h 956 2008-10-19 22:24:23Z hsc $ */

/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          C O R O U T I N E                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung des Koroutinenkonzepts.                                   */
/* Im Konstruktor wird der initialie Kontext der Koroutine eingerichtet.     */
/* Mit go() wird die erste Koroutine aktiviert. Alle weiteren                */
/* Koroutinenwechsel sollten mit resume() erfolgen.                          */
/* Um bei einem Koroutinenwechsel den Kontext sichern zu koennen, enthaelt   */
/* jedes Koroutinenobjekt eine Struktur toc, in dem die Werte der nicht-     */
/* fluechtigen Register gesichert werden koennen.                            */
/*****************************************************************************/

#ifndef __Coroutine_include__
#define __Coroutine_include__

extern "C"
{
	#include "machine/toc.h"
}




class Coroutine
{

public:

	toc regs;  


private:
	
	Coroutine(const Coroutine &copy); // Verhindere Kopieren
/* Hier muesst ihr selbst Code vervollstaendigen */     


public:

	/**
	 * Im Coroutinen Konstruktor werden die Registerwerte so initialisiert, 
	 * dass der Stackpointer initial auf tos zeigt und bei der ersten 
	 * Aktivierung die Ausf�hrung mit der Funktion kickoff beginnt, die 
	 * den this-Pointer des Coroutinenobjekts als Parameter auf dem Stack 
	 * vorfinden muss.
	 */
	Coroutine (void* tos);
    

	
	/**
	 * Diese Methode dient der ersten Aktivierung der ersten Koroutine 
	 * im System. Daher m�ssen hier keine Registerwerte gerettet werden.
	 */
	void go ();
    

	
	/**
	 * Mit dieser Methode wird ein Koroutinenwechsel ausgel�st. Die 
	 * aktuelle Belegung der nicht-fl�chtigen Register wird in dem 
	 * toc Element gesichert und durch die Werte von next (dem toc 
	 * Element der n�chsten Koroutine) ersetzt.
	 */
	void resume (Coroutine& next);
    

	/**
	 * Die Methode action stellt die eigentliche Aufgabe der Koroutine 
	 * dar. Da jedoch nicht alle Koroutinen im System dasselbe tun sollen, 
	 * kann action erst in einer spezialisierten Klasse (z.B. in Application) 
	 * definiert werden. 
	 */
	virtual void action () = 0;

};

#endif
