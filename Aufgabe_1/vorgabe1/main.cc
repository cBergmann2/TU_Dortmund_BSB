/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "machine/cgascr.h"
#include "machine/keyctrl.h"

int main()
{
/* Hier muesst ihr selbst Code vervollstaendigen */         
         
/* Hier muesst ihr selbst Code vervollstaendigen */ 
                         
/* Hier muesst ihr selbst Code vervollstaendigen */                         
 
	
	Keyboard_Controller test;
	
	Key key;

	do{

		key = test.key_hit();
		if((char)key == '1'){
			test.set_led(1, true);
			break;
		}
		else{
			test.set_led(1, false);
		}

		//key.ascii('0');
	}while(1);
	
	while(1);
   	return 0;
 }
