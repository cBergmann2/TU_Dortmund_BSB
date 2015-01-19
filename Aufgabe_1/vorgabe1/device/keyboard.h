/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Tastaturtreiber.                                                          */
/*****************************************************************************/

#ifndef __Keyboard_include__
#define __Keyboard_include__

#include "machine/keyctrl.h"
#include "machine/key.h"
#include "machine/plugbox.h"
#include "machine/pic.h"

#include "guard/gate.h"
#include "guard/guard.h"

#include "device/cgastr.h"

#include "meeting/semaphore.h"


#define CHAR_BUFFER_LENGTH 73
 
class Keyboard : public Gate, public Keyboard_Controller    
{        
private:

	Keyboard (const Keyboard &copy); // Verhindere Kopieren
	int addKey2Buffer(Key zeichen);
	Key removeKeyFromBuffer();
	
	
	Semaphore keySem;
	char zeichen;
	Key key;
	Key buffer[CHAR_BUFFER_LENGTH];
	unsigned int belegungsgrad, bufferHead, bufferTail;
	
         
public:

  Keyboard ();
  // PLUGIN: 'Anstoepseln' der Tastatur. Ab sofort werden Tasten erkannt.
  void plugin ();

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
  bool prologue ();
    

  /**
   * In dieser Methode soll das Auftreten des Tastendrucks einem eventuell wartenden Prozess signalisiert werden. 
   * Dazu wird ein Semaphor verwendet, dessen Zähler angibt, 
   * wieviele Tastaturcodes im Keyboard Puffer zur Abholung bereitstehen. 
   * Wenn ein Puffereintrag überschrieben werden muss, ohne dass der alte Wert von einem Anwendungsprozess abgefragt wurde, 
   * darf der Semaphor also nicht hochgezählt werden.
   */
  void epilogue ();
    
  /**
   * Diese Methode liefert die zuletzt gedrückte Taste (als Objekt der Klasse Key) zurück. 
   * Wenn gerade keine Taste gedrückt wurde, wird der aufrufende Anwendungsprozess solange blockiert. 
   * Dies wird durch die Verwendung eines Semaphors erreicht. Sobald der Tastencode abgeholt worden ist, 
   * sollte geeignet vermerkt werden, dass der verwendete Puffer nun für den nächsten Tastencode zur Verfügung steht.
   */
  Key getkey();

 };

#endif
