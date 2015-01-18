/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                        W A I T I N G R O O M                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Liste von Threads, die auf ein Ereignis warten.                           */
/*****************************************************************************/

#include "meeting/waitingroom.h"

//Der Destruktor entfernt alle noch wartenden Prozesse von der Liste und weckt sie zudem auf.
Waitingroom::~Waitingroom()
{
	
}

//Mit dieser Methode kann der angegebene Prozess customer vorzeitig aus dem Wartezimmer entfernt werden.
void Waitingroom::remove(Customer* customer)
{
	if(!customer) return;
	Queue::remove(customer);
	customer::waiting_in(NULL);
}