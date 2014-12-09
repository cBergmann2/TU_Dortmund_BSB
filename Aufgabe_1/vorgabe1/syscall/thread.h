/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             T H R E A D                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Benutzerschnittstelle eines Threads.                                      */
/*****************************************************************************/

#ifndef __thread_include__
#define __thread_include__

#include "thread/entrant.h"

/**
 * Die Klasse Thread implementiert die Benutzerschnittstelle eines Fadens. 
 * Zur Zeit ist Thread nichts weiter als ein neuer Name für die Klasse Entrant.
 */
class Thread
{

private:
      Thread (const Thread &copy); // Verhindere Kopieren

public:
	
	Thread (void* tos) : 
		Entrant(tos)
	{}
          
};

#endif
