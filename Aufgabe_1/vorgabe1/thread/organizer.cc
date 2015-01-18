/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          O R G A N I Z E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Ein Organizer ist ein spezieller Scheduler, der zusaetzlich das Warten    */
/* von Threads (Customer) auf Ereignisse erlaubt.                            */
/*****************************************************************************/

#include "thread/organizer.h"

/**
 * Mit dieser Methode kann sich der laufende Prozess selbst 
 * blockieren. Er gibt also den Prozessor an den nächsten 
 * lauffähigen Prozess ab. Außerdem vermerkt er, auf welches 
 * Ereignis (in welchem Wartezimmer) er nun wartet.
 */
void Organizer::block (Customer& customer, Waitingroom& waitingroom)
{

}


/**
 * Mit dieser Methode kann ein schlafender Prozess geweckt, also 
 * wieder auf die Ready-Liste gesetzt werden. Dabei sollte auch 
 * markiert werden, dass der Prozess nun auf kein Ereignis mehr 
 * wartet.
 */
void Organizer::wakeup (Customer& customer)
{

}


/**
 * Mit dieser Methode kann ein Prozess einen anderen (that) beenden. 
 * Wenn der Prozess that auf der Ready-Liste steht, kann die 
 * kill-Methode des Schedulers verwendet werden. Wartet er dagegen 
 * auf ein Ereignis, so muss er von dessen Liste (also aus dem 
 * Wartezimmer) heruntergenommen werden. 
 */
void Organizer::kill (Customer& that)
{

}