/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "device/cgastr.h"
#include "machine/keyctrl.h"

#include "machine/cpu.h"
#include "machine/pic.h"

#define BUFFERSIZE 100
CGA_Stream kout;

void decrementPos();
bool compare(char* str1, unsigned int length1, char* str2, unsigned int length2);

int main()
{
  PIC pic;
  pic.allow(keyboard);
  CPU cpu;
  cpu.enable_int();
  
  int i=0;
  while(1)
  {
    i++;
    if(i>0xF0000){
      kout.print(".",1);	
      i=0;
    }
  }
  return 0;
}

 
void decrementPos()
{
    int zeile, spalte;
    
    kout.getpos(spalte,zeile);
    
    if(spalte==0)
    {
	spalte = 79;
	zeile--;
    }else{
	spalte--;
    }
    
    kout.setpos(spalte, zeile);
  
}


bool compare(char* str1, unsigned int length1, char* str2, unsigned int length2)
{
	if(length1 != length2)
		return false;

	for(int i=0; i<length1; i++)
	{
		if(*str1 != *str2)
			return false;
		
		str1++;
		str2++;
	}
	return true;
}
