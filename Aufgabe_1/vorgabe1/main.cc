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
		if(key.asc == '1'){
			test.set_led(1, true)
		}
		else{
			test.set_led(1, false)
		}

		key.asc = '0';
	}while(1);

   	return 0;
 }
