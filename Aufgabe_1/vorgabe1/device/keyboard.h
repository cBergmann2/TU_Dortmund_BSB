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
#include "guard/gate.h"
#include "machine/key.h"
#include "machine/plugbox.h"
#include "machine/pic.h"
 
class Keyboard : public Gate, public Keyboard_Controller    
{        
private:
      Keyboard (const Keyboard &copy); // Verhindere Kopieren

/* Hier muesst ihr selbst Code vervollstaendigen */                 
         
public:
/* Hier muesst ihr selbst Code vervollstaendigen */ 
	  Keyboard ();
      // PLUGIN: 'Anstoepseln' der Tastatur. Ab sofort werden Tasten erkannt.
      void plugin ();
	  void trigger();

/* Hier muesst ihr selbst Code vervollstaendigen */ 
        
 };

#endif
