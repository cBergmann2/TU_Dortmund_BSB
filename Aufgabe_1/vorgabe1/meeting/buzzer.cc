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
virtual Buzzer::~Buzzer()
{

}
	
	
/**
 * Wird von Glöckner aufgerufen, wenn die Wartezeit abgelaufen ist. Weckt ggfs. schlafende Threads.
 */
void Buzzer::ring()
{

}
	
/**
 * Stellen des Weckers.
 */
void Buzzer::set (int ms)
{

}
	
/**
 * Schlafen, bis der Wecker klingelt. 
 */
void Buzzer::sleep ()
{

}