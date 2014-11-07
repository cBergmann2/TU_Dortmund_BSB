/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

/* INCLUDES */

#include "user/appl.h"
#include "device/cgastr.h"
#include "device/keyboard.h"
#include "machine/cpu.h"

         
/* GLOBALE VARIABLEN */
extern CGA_Stream kout;




void Application::action ()
{

  Keyboard board;
  CPU cpu;
  int i=0, count=0; 
  int x,y, x2,y2;
  //Initialisierungen
  kout.setpos(0,1);
  board.plugin();
  
  
  cpu.enable_int();
  
  
  while (1)
  {
      i++;
      if(i>0x500000)
      {
		i=0;
		if(count>0xFFFF) count=0;
		kout.getpos(x,y); //Position Speichern
		
		//Ausgabe 
		kout << " " << count;
		kout.flush();

		//vergleichswert besorgen
		kout.getpos(x2,y2);
		if(y2 > y)
		{
			kout.setpos(0,y);
		}

		count++;
      }
  }

}
