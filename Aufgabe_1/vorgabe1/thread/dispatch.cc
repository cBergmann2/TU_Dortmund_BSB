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
Dispatcher::Dispatcher(){
	this->lifePtr = 0;
}


/**
* Mit dieser Methode wird die Koroutine first im Life-Pointer
* vermerkt und gestartet.
*/
void Dispatcher::go(Coroutine& first){
	this->lifePtr = first;
}


/**
* Diese Methode setzt den Life-Pointer auf next und führt einen
* Koroutinenwechsel vom alten zum neuen Life-Pointer durch.
*/
void Dispatcher::dispatch(Coroutine& next){
	//sicherheit
	if(!lifePtr) return;
	
	//Koroutinenwechsel durchführen
	lifePtr->resume(next);

	//neuen Life-Pointer setzen
	lifePtr = next;
}


/**
* Hiermit kann abgefragt werden, welche Koroutine gerade im
* Besitz des Prozessors ist.
*/
Coroutine* Dispatcher::active(){
	return this->lifePtr;
}
