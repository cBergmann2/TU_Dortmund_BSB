/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung des Schedulers.                                           */
/*****************************************************************************/

#ifndef __schedule_include__
#define __schedule_include__

#include "thread/dispatch.h"
#include "thread/coroutine.h"
#include "thread/entrant.h"
#include "object/queue.h"
#include "device/cgastr.h" 

class Scheduler : public Dispatcher{
private:

	Queue readyList;

	Scheduler (const Scheduler &copy){} // Verhindere Kopieren
	
public:
	
	Scheduler(){}
	
	/**
	 * Mit dieser Methode wird der Prozess that beim Scheduler angemeldet. 
	 * Er wird an das Ende der Ready-Liste angef�gt.
	 */
	void ready (Entrant& that);
    

	/**
	 * Diese Methode setzt das Scheduling in Gang, indem der erste Prozess
	 * von der Ready-Liste entfernt und aktiviert wird.
	 */
	void schedule ();
    

	/**
	 * Hiermit kann sich ein Prozess selbst beenden. Er wird nun nicht 
	 * wieder an das Ende der Ready-Liste angef�gt. Statt dessen wird 
	 * nur der erste Prozess von der Ready-Liste heruntergenommen und aktiviert.
	 */
	void exit ();
    

	/**
	 * Mit dieser Methode kann ein Prozess einen anderen (that) beenden. 
	 * Der Prozess that wird einfach von der Ready-Liste entfernt und 
	 * erh�lt somit nie wieder den Prozessor.
	 */
	void kill (Entrant& that);
    

	/**
	 * Hiermit kann ein Prozesswechsel ausgel�st werden, ohne dass der 
	 * aufrufende Entrant wissen muss, welche anderen Entrant Objekte 
	 * im System existieren und welcher davon sinnvollerweise aktiviert 
	 * werden sollte. Diese Entscheidung trifft der Scheduler anhand der 
	 * Eintr�ge seiner Ready-Liste. Im derzeitigen System soll er den 
	 * gerade laufenden Prozess an das Ende der Ready-Liste anf�gen und 
	 * den ersten aktivieren. 
	 */
	void resume ();
    
 };

#endif
