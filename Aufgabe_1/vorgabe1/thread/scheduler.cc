/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung des Schedulers.                                           */
/*****************************************************************************/

#include"scheduler.h"

Scheduler::Scheduler(const Scheduler &copy){} // Verhindere Kopieren

/**
* Mit dieser Methode wird der Prozess that beim Scheduler angemeldet.
* Er wird an das Ende der Ready-Liste angef�gt.
*/
void Scheduler::ready(Entrant& that){}


/**
* Diese Methode setzt das Scheduling in Gang, indem der erste Prozess
* von der Ready-Liste entfernt und aktiviert wird.
*/
void Scheduler::schedule(){}


/**
* Hiermit kann sich ein Prozess selbst beenden. Er wird nun nicht
* wieder an das Ende der Ready-Liste angef�gt. Statt dessen wird
* nur der erste Prozess von der Ready-Liste heruntergenommen und aktiviert.
*/
void Scheduler::exit(){}


/**
* Mit dieser Methode kann ein Prozess einen anderen (that) beenden.
* Der Prozess that wird einfach von der Ready-Liste entfernt und
* erh�lt somit nie wieder den Prozessor.
*/
void Scheduler::kill(Entrant& that){}


/**
* Hiermit kann ein Prozesswechsel ausgel�st werden, ohne dass der
* aufrufende Entrant wissen muss, welche anderen Entrant Objekte
* im System existieren und welcher davon sinnvollerweise aktiviert
* werden sollte. Diese Entscheidung trifft der Scheduler anhand der
* Eintr�ge seiner Ready-Liste. Im derzeitigen System soll er den
* gerade laufenden Prozess an das Ende der Ready-Liste anf�gen und
* den ersten aktivieren.
*/
void Scheduler::resume(){}