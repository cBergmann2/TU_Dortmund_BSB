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

void Panic::trigger(){
	//Fehlermeldung anhalten
	kout << "Fehler: Interrupt eingetreten der von keiner ISR beahndelt wird!\n";
	kout << "->System wird angehlaten";

	//System anhalten
	CPU cpu;
	cpu.halt();
}


/**
  * Einfachste Form der Unterbrechungsbehandlung: Es wird eine 
  * Fehlermeldung ausgegeben und der Prozessor angehalten. 
  */
bool Panic::prologue()
{
  
}