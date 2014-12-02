/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            E N T R A N T                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Eine Koroutine, die vom Scheduler verwaltet wird.                         */
/*****************************************************************************/

#ifndef __entrant_include__
#define __entrant_include__

/* Hier muesst ihr selbst Code vervollstaendigen */ 
        
class Entrant 
/* Hier muesst ihr selbst Code vervollstaendigen */         
 {
private:
      Entrant (const Entrant &copy); // Verhindere Kopieren
/* Hier muesst ihr selbst Code vervollstaendigen */          

	/**
	 * Der Entrant Konstruktor gibt nur den Parameter tos an den Coroutinen Konstruktor weiter. 	
	 */
	Entrant (void* tos);
    

 };

#endif
