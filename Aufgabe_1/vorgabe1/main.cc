/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */

/* Hier muesst ihr selbst Code vervollstaendigen */ 


#include "user/appl.h"
#include "device/cgastr.h"
#include "machine/plugbox.h"
#include "guard/guard.h"
#include "user/loop.h"
#include "user/loop2.h"
#include "thread/scheduler.h"


#define STACK_SIZE 1024


//Globale Instanzen
CGA_Stream kout;
Plugbox plugbox;
Guard guard;
Scheduler scheduler;


unsigned char stack1[STACK_SIZE];
unsigned char stack2[STACK_SIZE];

int main()
{
	Loop a(stack2+STACK_SIZE, 'a');
	Loop2 b(stack1+STACK_SIZE, 'b');	
	
	scheduler.ready(a);
	scheduler.ready(b);
	scheduler.schedule();
	
	while(1);
}
