/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               B U Z Z E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe des "Weckers" koennen Prozesse eine bestimmte Zeit lang         */
/* schlafen und sich dann wecken lassen.                                     */
/*****************************************************************************/

/* INCLUDES */
#include "meeting/buzzer.h"

extern Guarded_Organizer scheduler;
extern Bellringer bellringer;

/**
 * Konstruktor. Der Wecker ist zunächst noch abgeschaltet.
 */
Buzzer::Buzzer ()
{

}
	
/**
 * Im Destruktor wird der Glöckner (Bellringer) informiert, dass 
 * er nicht mehr läuten muss. Außerdem werden alle wartenden Threads geweckt.
 */
Buzzer::~Buzzer()
{
	bellringer.cancel(this);
	Thread *thread = (Thread*)dequeue();
	
	while(thread)
	{
		thread->waiting_in(NULL);
		scheduler.ready(*thread);
		thread = (Thread*)dequeue();
	}
	
}
	
	
/**
 * Wird von Glöckner aufgerufen, wenn die Wartezeit abgelaufen ist. Weckt ggfs. schlafende Threads.
 */
void Buzzer::ring()
{
	Thread *thread = (Thread*)dequeue();
	
	while(thread)
	{
		thread->waiting_in(NULL);
		scheduler.ready(*thread);
		thread = (Thread*)dequeue();
	}

}
	
/**
 * Stellen des Weckers.
 */
void Buzzer::set (int ms)
{
	bellringer.job(this, ms);
}
	
/**
 * Schlafen, bis der Wecker klingelt. 
 */
void Buzzer::sleep ()
{
	Thread *thread = (Thread*)scheduler.active();
	scheduler.block(*thread, *this);
}
