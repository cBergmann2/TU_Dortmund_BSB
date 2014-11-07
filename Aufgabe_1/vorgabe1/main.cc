/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */

/* Hier muesst ihr selbst Code vervollstaendigen */ 


#include "user/appl.h"
#include "device/cgastr.h"
#include "machine/plugbox.h"
#include "guard/guard.h"


//Globale Instanzen
Guard guard;
CGA_Stream kout;
Plugbox plugbox;

int main()
{
  Application appl;
  
  appl.action();
  
  while(1);
}
