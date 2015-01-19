/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                   G U A R D E D _ S E M A P H O R E                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zum Semaphor.                                   */
/*****************************************************************************/

#include "syscall/guarded_semaphore.h"

/**
 * Der Konstruktor reicht nur den Parameter c an den Konstruktor der Basisklasse weiter. 
 */
Guarded_Semaphore::Guarded_Semaphore (int c) : 
	Semaphore(c);
{
	
}
	
/**
 * siehe Semaphore::p ()
 */
void Guarded_Semaphore::p ()
{
	Secure section;
	Semaphore::p();
}
	
/**
 * siehe Semaphore::v ()
 */
void Guarded_Semaphore::v ()
{
	Secure section;
	Semaphore::v();
}
	
/**
 * siehe Semaphore::wait ()
 */
void Guarded_Semaphore::wait ()
{
	p();
}
	
/**
 * siehe Semaphore::signal () 
 */
void Guarded_Semaphore::signal ()
{
	v();
}