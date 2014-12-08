/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Tastaturtreiber.                                                          */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
/* Hier muesst ihr selbst Code vervollstaendigen */ 

#include "device/keyboard.h"

extern Plugbox plugbox;
extern CGA_Stream kout;
extern Guard guard;

 
Keyboard::Keyboard() :
	Gate(),
	Keyboard_Controller(),
	zeichen(0)
{}

void Keyboard::plugin()
{
	PIC pic;

	plugbox.assign(plugbox.keyboard, *this);
	pic.allow(keyboard); //1 - Keyboard, 0 - timer

	return;
}

/**
  * Mit dieser Methode wird auf die Unterbrechungen durch die Tastatur 
  * reagiert. Da bei jedem Tastendruck mehrere Unterbrechungen ausgelöst 
  * werden, ist nicht in jedem Fall mit einem verwertbaren ASCII-Code zu 
  * rechnen. Nur wenn die Methode key_hit der Basisklasse Keyboard_Controller 
  * einen gültigen Key liefert, konnte ein vollständiger Scancode ermittelt 
  * werden. Für "normale" Tasten existiert dann auch ein ASCII-Code ungleich Null.
  * 
  * Falls Ctrl-Alt-Delete gedrückt wurde, soll ein Reboot ausgelöst werden. 
  * Außerdem soll die Ausführung eines Epilogs angefordert werden.
  */
bool Keyboard::prologue ()
{
	char zeichen;
	Key input;

	input=this->key_hit();

	do
	{	//Der erste Eintrag sollte gültig sein, da sonst kein Interrupt 
		// ausgelöst wurde.
		
		//CTRL + ALT + DEL abfragen
		if((input.ctrl()==true) && (input.alt()==true) && (input.scancode()==0x53))
		{
			this->reboot();
		}
		else
		{
		
			//Gültiges Zeichen ausgelesen				
			zeichen = input.ascii();
			if(zeichen)	//Zeichen interpretieren
			{
				//Für Ausgabe vorbereiten
				//Theoretisch in Ringbuffer speichern, 
				//damit weitere Zeichen ausgelesen werden können
				if(this->zeichen!=0) 
				{
					//bereits ein Zeichen im buffer.
					return false;
				}
				this->zeichen = zeichen;
				
				//Epilogue anfordern
				return true;
			}
		}
		
		//weitere Zeichen auslesen, wenn vorhanden
		input=this->key_hit();	
	}while(input.valid());	
	
	return false;
}
    

/**
  * Hier wird das im Rahmen der Prolog-Behandlung ausgelesene Zeichen auf dem 
  * Bildschirm mit Hilfe des globalen CGA_Stream Objekts kout ausgegeben.
  */
void Keyboard::epilogue ()
{
	kout << zeichen;
	
	//Buffer zurücksetzen
	zeichen = 0;
}
