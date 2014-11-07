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
 
Keyboard::Keyboard() :
	Gate(),
	Keyboard_Controller()
{}

void Keyboard::plugin()
{
	PIC pic;

	plugbox.assign(plugbox.keyboard, *this);
	pic.allow(keyboard); //1 - Keyboard, 0 - timer

	return;
}

void Keyboard::trigger()
{
  char zeichen;
  Key input;
  static int x=0;
  
  input=this->key_hit();

  if(input.valid())
  {
    if((input.ctrl()==true) && (input.alt()==true) && (input.ascii()==(char)127))
		this->reboot();
    else
    {
		kout.setpos(x,0);
		if(++x >= 80)
			x=0;
			
		kout.print(input.ascii(),1);		
    }
  }
}

