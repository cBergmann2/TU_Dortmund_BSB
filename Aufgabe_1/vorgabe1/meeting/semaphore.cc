/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                           S E M A P H O R E                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Semaphore werden zur Synchronisation von Threads verwendet.               */
/*****************************************************************************/

#include "meeting/semaphore.h"

//Der Konstruktor initialisiert den Semaphorzähler mit dem angegebenen Wert c
Semaphore::Semaphore(int c)
{

}

//Warteoperation: Sofern der Semaphorzähler größer als Null ist, wird er nur um eins erniedrigt. 
//Anderenfalls wird der aktuell laufende Prozess (ein Customer Objekt) an die Warteliste angefügt und blockiert.
void Semaphore::p()
{

}

//Freigabeoperation: Wenn auf der Warteliste mindestens ein Customer eingetragen ist, 
//wird der erste davon aufgeweckt. Anderenfalls wird der Semaphorzähler um eins erhöht.
void Semaphore::v()
{

}
