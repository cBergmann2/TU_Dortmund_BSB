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
         
/* GLOBALE VARIABLEN */
extern CGA_Stream kout;



void Application::action ()
{

	Keyboard board;
	CPU cpu;
	int i=0, count=0; 
	int x,y, x2,y2;
	char zeichen;
	int wait=0;

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
			if(count>=80) count=0;
			
			{ Secure section;
				
				//Zeichen in 2. Zeile ausgeben
				kout.setpos(count%10,1);
				
				//Hier kann ein Fehler durch Interrupt entstehen

				//provozieren
				while(wait++ < 0x500000);
				wait=0;
				
				zeichen = count%10+'0';			
				kout.print(&zeichen,1);
				kout.print(" ",1);
			}
			
			/* 2.Testprogramm
			
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

			*/

			
		
		
		
			count++;

		}
	}

}
