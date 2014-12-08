/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                       S T R I N G B U F F E R                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Stringbuffer stellt einen Puffer fuer die Sammlung von Zeichen */
/* zur Darstellung auf dem Bildschirm oder anderen Ausgabegeraeten bereit.   */
/* Die Ausgabe der Zeichen erfolgt, sobald der Puffer voll ist oder wenn     */
/* explizit die Methode flush() aufgerufen wird.                             */
/* Da Stringbuffer geraeteunabhaengig sein soll, ist flush() eine virtuelle  */
/* Methode, die von den abgeleiteten Klassen definiert werden muss.          */
/*****************************************************************************/

#include "object/strbuf.h"


Stringbuffer::Stringbuffer()
{
  int i=0;
  char* ptr = (char*)(this->buffer);
  this->count = 0;
  
  for(;i<BUF_SIZE; i++)
    *(ptr++)=0;
}

Stringbuffer::Stringbuffer(const Stringbuffer &copy){
/*
  int i=0;
  char* ptr = (char*)(copy.buffer);
  char* thisPtr = (char*)(this->buffer);
  this->count = copy.count;
  for(;i<BUF_SIZE;i++)
  {
      *(thisPtr++) = *(ptr++);
  }
*/
}

void Stringbuffer::put (char c)
{
	if(count==BUF_SIZE) flush();
	
	buffer[count++] = c;
}
