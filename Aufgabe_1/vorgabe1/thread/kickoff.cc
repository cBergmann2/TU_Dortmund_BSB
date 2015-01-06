/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K I C K O F F                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Funktion zum Starten einer Koroutine.                                     */
/* Da diese Funktion nicht wirklich aufgerufen, sondern nur durch eine       */
/* geschickte Initialisierung des Stacks der Koroutine angesprungen wird,    */
/* darf sie nie terminieren. Anderenfalls wuerde ein sinnloser Wert als      */
/* Ruecksprungadresse interpretiert werden und der Rechner abstuerzen.       */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
 
#ifndef __KICKOFF_CC
#define __KICKOFF_CC

#include "thread/coroutine.h"
#include "guard/guard.h"

extern Guard guard;

/**
 * Diese Methode realisiert den Sprung von der C Ebene zur 
 * C++ Ebene, indem sie ganz einfach die Methode action() 
 * des als Parameter vorgefundenen Koroutinenobjektes object aufruft.
 */
void kickoff (Coroutine* object)
{
	guard.leave();	//verlässt den geschützten Bereich nachdem die resume-Funktion aufgerufen wurde
	object->action();
}

#endif	//__KICKOFF_CC
 
