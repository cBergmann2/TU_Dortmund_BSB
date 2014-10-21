/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "machine/cgascr.h"

int main()
{
/* Hier muesst ihr selbst Code vervollstaendigen */         
         
/* Hier muesst ihr selbst Code vervollstaendigen */ 
                         
/* Hier muesst ihr selbst Code vervollstaendigen */                         
 
   CGA_Screen t;
	t.setpos(0,0);
	t.print("hallo1", 6);

	t.setpos(0,1);
	t.print("hal\nlo2", 7);
	

t.setpos(2,8);
t.print("hallo2", 6);

t.setpos(76,24);
t.print("12345678901234567890", 20);
   return 0;
 }
