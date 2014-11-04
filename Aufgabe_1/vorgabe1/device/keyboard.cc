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

 
Keyboard::Keyboard() :
	Gate(),
	Keyboard_Controller()
{}

void Keyboard::plugin()
{
	Pic pic;

	plugbox.assign(plugbox.keyboard, this);
	pic.allow(keyboard); //1 - Keyboard, 0 - timer

	return;
}

void Keyboard::trigger()
{
	char zeichen;
	Key input;

	input=this->key_hit();
	
	if(input.valid())
	{
		if(input.ctrl_left()==true && input.alt_left()==true && input.ascii==127)
			this->reboot();
		else
		{
			zeichen=input.ascii();
			kout << zeichen;
		}
	}

}

