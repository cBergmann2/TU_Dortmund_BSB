/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          D I S P A T C H E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung des Dispatcher.                                           */
/* Der Dispatcher verwaltet den life-Pointer, der die jeweils aktive         */
/* Koroutine angibt. mit go() wird der life Pointer initialisiert und die    */
/* erste Koroutine gestartet, alle weiteren Kontextwechsel werden mit        */
/* dispatch() ausgeloest. active() liefert den life Pointer zurueck.         */
/*****************************************************************************/

#ifndef __dispatch_include__
#define __dispatch_include__

/* Hier muesst ihr selbst Code vervollstaendigen */ 
        
class Dispatcher
 {
private:
      Dispatcher(const Dispatcher &copy); // Verhindere Kopieren
/* Hier muesst ihr selbst Code vervollstaendigen */ 


	/**
	 * Der Konstruktor initialisiert den Life-Pointer mit Null, 
	 * um anzuzeigen, dass noch keine Koroutine bekannt ist.
	 */
	Dispatcher ()
    

	
	/**
	 * Mit dieser Methode wird die Koroutine first im Life-Pointer 
	 * vermerkt und gestartet.
	 */
	void go (Coroutine& first)
    

	/**
	 * Diese Methode setzt den Life-Pointer auf next und f�hrt einen 
	 * Koroutinenwechsel vom alten zum neuen Life-Pointer durch.
	 */
	void dispatch (Coroutine& next)
    

	/**
	 * Hiermit kann abgefragt werden, welche Koroutine gerade im 
	 * Besitz des Prozessors ist. 
	 */
	Coroutine* active ()
    

 };

#endif
