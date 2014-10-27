/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "device/cgastr.h"
#include "machine/keyctrl.h"

CGA_Stream kout;

int main()
{
	//Initialisierungen
	unsigned int fehler=0;
	Keyboard_Controller kc;
	Key input;
	unsigned char inbuffer[11] = {0};
	unsigned char index=0;
	unsigned char zeichen;
	
	//Bildshirm initialisieren
	kout << "Guten Tag,\n das ist OOSTUBS, ein kleines OS von Stundenten für Studenten";
	
	

	do
	{
		kout << endl << "Geben sie hier eine Zeichenkette ein: ";
		
		//Eingabe abfragen
		index=0;
		do
		{
			//!!! Achtung !!!
			//Momentan wird die Anzeige nicht in der Konsole angezeigt
			//Desweiteren muss dann auch das Backspace berücksichtigt werden
			input = kc.key_hit();
			zeichen = input.ascii();
			kout.print(&zeichen, 1);
			
			if(zeichen == '\n')
			{
				inbuffer[index] = 0;
				break;
			}else{
				inbuffer[index] = zeichen;
				index++;
				if(index==10)
				{
					fehler = 1;
					goto ERROR;
				}
			}	
		}while(1);
		
		//Zahl ausgeben
		kout << endl << "Sie haben folgende Zeichenkette eingeben: ";
		kout << inbuffer;
		kout << endl;
	} while (1);
   
ERROR:
	//Error-handler:
	kout << endl << endl << "Hier ist ein Fehler aufgetreten." << endl;
	kout << "Fehlernummer "  << fehler;
	while(1);
   
   return 0;
 }
