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
	remove(thread);
	scheduler.ready(thread);
}
	
	
/**
 * Wird von Glöckner aufgerufen, wenn die Wartezeit abgelaufen ist. Weckt ggfs. schlafende Threads.
 */
void Buzzer::ring()
{
	remove(thread);
	scheduler.ready(thread);
}
	
/**
 * Stellen des Weckers.
 */
void Buzzer::set (int ms)
{
	us=ms;
}
	
/**
 * Schlafen, bis der Wecker klingelt. 
 */
void Buzzer::sleep ()
{
	thread=scheduler.active();
	scheduler.kill(thread);
	thread.waiting_in(this);
	bellringer.job(this, us);
}
