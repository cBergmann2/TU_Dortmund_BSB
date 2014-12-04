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

#include "dispatch.h"

/**
* Der Konstruktor initialisiert den Life-Pointer mit Null,
* um anzuzeigen, dass noch keine Koroutine bekannt ist.
*/
Dispatcher::Dispatcher()
{
	this->lifePtr = 0;
}


/**
* Mit dieser Methode wird die Koroutine first im Life-Pointer
* vermerkt und gestartet.
*/
void Dispatcher::go(Coroutine& first)
{
	//Prozess speichern
	this->lifePtr = &first;
	
	//und ausführen
	first.go();
}


/**
* Diese Methode setzt den Life-Pointer auf next und führt einen
* Koroutinenwechsel vom alten zum neuen Life-Pointer durch.
*/
void Dispatcher::dispatch(Coroutine& next)
{
	//Den aktuellen Prozess zwischenspeichern
	Coroutine* old = lifePtr;

	//sicherheit
	if(!lifePtr) return;
	
	
	//=================== ACHTUNG ================//
	// lifePtr wird von Schedule::resume benutzt,
	// um den aktuellen Prozess abzufragen
	//============================================//
	
	//Life-Pointer neu setzen
	lifePtr = &next;
	
	//Koroutinenwechsel durchführen
	old->resume(next);	
}


/**
* Hiermit kann abgefragt werden, welche Koroutine gerade im
* Besitz des Prozessors ist.
*/
Coroutine* Dispatcher::active()
{
	return this->lifePtr;
}
