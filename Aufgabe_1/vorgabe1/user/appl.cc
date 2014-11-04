/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

/* INCLUDES */

#include "user/appl.h"
#include "device/cgastr.h"
/* Hier muesst ihr selbst Code vervollstaendigen */         
         
/* GLOBALE VARIABLEN */

extern CGA_Stream kout;
/* Hier muesst ihr selbst Code vervollstaendigen */ 
         
void Application::action ()
{
/* Hier muesst ihr selbst Code vervollstaendigen */ 

  int i=0;
  bool b=true;
  while (1)
  {
      i++;
      if(i>0xF000)
      {
	i=0;
	if(b)
	  kout.show(0,0,' ');
	else
	  kout.show(0,0,'*');
	b=!b;
      }
  }

}
