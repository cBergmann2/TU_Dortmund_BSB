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
  int x,y;
  
  input=this->key_hit();

  if(input.valid())
  {
    if((input.ctrl()==true) && (input.alt()==true) && (input.ascii()==(char)127))
      this->reboot();
    else
    {
      kout.flush();
      kout.getpos(x,y);
      kout.setpos(0,0);
      zeichen=input.ascii();
      kout << zeichen;
      kout.flush();
      kout.setpos(x,y);
    }
  }
}

