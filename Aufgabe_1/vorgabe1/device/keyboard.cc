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
extern Semaphore keyboardsem;

 
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

	//Zeichenpuffer vorbereiten
	this->belegungsgrad = 0;
	this->bufferHead = 0;
	this->bufferTail = 0;

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
				
				if (this->key.ascii() != 0)
				{
					//bereits ein Zeichen im buffer.
					return false;
				}
				this->key = intput;
				//this->zeichen = zeichen;

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
  * In dieser Methode soll das Auftreten des Tastendrucks einem eventuell wartenden Prozess signalisiert werden.
  * Dazu wird ein Semaphor verwendet, dessen Zähler angibt,
  * wieviele Tastaturcodes im Keyboard Puffer zur Abholung bereitstehen.
  * Wenn ein Puffereintrag überschrieben werden muss, ohne dass der alte Wert von einem Anwendungsprozess abgefragt wurde,
  * darf der Semaphor also nicht hochgezählt werden.
  */
void Keyboard::epilogue ()
{
	if (this->addKey2Buffer(this->key)){
		kout << "Tasterturpuffer voll";
	}
	else{
		//Semaphore hochzählen
		this->keySem.v();
		//Bufferzustand auf leer setzen
		this->key.ascii(0);
	}

	/*
	kout << zeichen;
	
	//Buffer zurücksetzen
	zeichen = 0;
	*/
}

/**
* Diese Methode liefert die zuletzt gedrückte Taste (als Objekt der Klasse Key) zurück.
* Wenn gerade keine Taste gedrückt wurde, wird der aufrufende Anwendungsprozess solange blockiert.
* Dies wird durch die Verwendung eines Semaphors erreicht. Sobald der Tastencode abgeholt worden ist,
* sollte geeignet vermerkt werden, dass der verwendete Puffer nun für den nächsten Tastencode zur Verfügung steht.
*/
Key Keyboard::getkey(){
	
	this->keySem.p();
	return this->removeKeyFromBuffer();
}


int addKey2Buffer(Key zeichen){
	if (this->belegungsgrad < CHAR_BUFFER_LENGTH){
		this->buffer[this->bufferTail] = zeichen;
		this->bufferTail = (bufferTail + 1) % CHAR_BUFFER_LENGTH;
		this->belegungsgrad++;

		return 0; //Zeichen konnte erfolgreich in Buffer eingefügt werden
	}
	return -1; //Buffer ist bereits voll
}

Key removeKeyFromBuffer(){
	Key tmp;

	tmp = this->buffer[this->bufferHead];
	this->belegungsgrad--;
	this->bufferHead = (this->bufferHead + 1) % CHAR_BUFFER_LENGTH;
	return tmp;
}