/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "device/cgastr.h"
#include "machine/keyctrl.h"

#define BUFFERSIZE 100
CGA_Stream kout;

void decrementPos();
bool compare(char* str1, unsigned int length1, char* str2, unsigned int length2);

int main()
{
kout << -24400;
	//Initialisierungen
	unsigned int fehler=0;
	Keyboard_Controller kc;
	Key input;
	char inbuffer[BUFFERSIZE] = {0};
	unsigned char index=0;
	char zeichen;

	
	kc.set_repeat_rate(0xFF,0x03);
	

	//Bildshirm initialisieren
	kout << "Guten Tag,\n das ist OOSTUBS, ein kleines OS von Stundenten fuer Studenten";
	kout << endl;
	kout.flush();
	

	kout << "\nJetzt folgen zunaechst ein paar Testausgaben:\n";
	kout << "int 25500: " << 25500 << " hex: " << hex << 25500 << " oct: " << oct << 25500;
	kout << endl << dec;
	kout << "short 25500: " << (short)25500 << " hex: " << hex << (short)25500 << " oct: " << oct << (short)25500;
	kout << endl;
	kout << "Zeiger-Typ: " << &index;

	kout << endl;	
kout << "int -25500: " << dec <<(signed int)-25500 << oct<< "oct: " << -25500 << "hex: " << hex << -25500;

	kout << endl;
	do
	{
		kout << endl << "Geben sie hier eine Zeichenkette ein (max. 10 Zeichen): ";
		kout.flush();

		//Eingabe abfragen
		index=0;
		do
		{
			//!!! Achtung !!!
			//Momentan wird die Anzeige nicht in der Konsole angezeigt
			//Desweiteren muss dann auch das Backspace berücksichtigt werden
			
			do //Zeichen abfangen und auf gültigkeit prüfen
 			{
				input = kc.key_hit();
			}while(!input.valid());
			
			//Ausgelesenes zeichen abfangen
			zeichen = input.ascii();
			if(zeichen == '\b')
			{
			      if(index!=0)
			      {
			      	 decrementPos();
			     	 kout.print(" ",1);	//Leeres Zeichen einfügen
			     	 decrementPos();
			 	 index--;
			      }
			}else{
			      kout.print(&zeichen, 1);
			      
			      if(zeichen == '\n')
			      {
				      inbuffer[index] = 0;
				      break;
			      }else{
				      inbuffer[index] = zeichen;
				      index++;
				      if(index==(BUFFERSIZE-1))
				      {
					      fehler = 1;
					      goto ERROR;
				      }
			      }
			}
			
				
		}while(1);
		
		if(compare("restart",7,(char*)inbuffer, index))
			kc.reboot();

		//Zahl ausgeben
		kout << endl << "Sie haben folgende Zeichenkette eingeben: ";
		kout << inbuffer;
		kout << endl;

		kc.set_repeat_rate(0x00,0x03);
	} while (1);
   
ERROR:
	//Error-handler:
	kout << endl << endl << "Hier ist ein Fehler aufgetreten." << endl;
	kout << "Fehlernummer "<< dec  << fehler;
	kout.flush();
	while(1);
   
   return 0;
}

 
void decrementPos()
{
    int zeile, spalte;
    
    kout.getpos(spalte,zeile);
    
    if(spalte==0)
    {
	spalte = 79;
	zeile--;
    }else{
	spalte--;
    }
    
    kout.setpos(spalte, zeile);
  
}


bool compare(char* str1, unsigned int length1, char* str2, unsigned int length2)
{
	if(length1 != length2)
		return false;

	for(int i=0; i<length1; i++)
	{
		if(*str1 != *str2)
			return false;
		
		str1++;
		str2++;
	}
	return true;
}
