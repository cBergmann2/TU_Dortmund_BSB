/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Standard Unterbrechungsbehandlung.                                        */
/*****************************************************************************/

#include "panic.h"

extern CGA_Stream kout;

Panic::Panic() :
  Gate()
{

}

/**
  * Einfachste Form der Unterbrechungsbehandlung: Es wird eine 
  * Fehlermeldung ausgegeben und der Prozessor angehalten. 
  */
bool Panic::prologue()
{
//Aus der vorherigen Mehtode trigger() kopiert:

  //Fehlermeldung anhalten
	kout << endl;
	kout << "Fehler: Interrupt eingetreten der von keiner ISR beahndelt wird!\n";
	kout << "->System wird angehalten";
	kout.flush();
	
	//System anhalten
	CPU cpu;
	cpu.halt();
}
