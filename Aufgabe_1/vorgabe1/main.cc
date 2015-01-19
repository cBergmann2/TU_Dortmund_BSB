/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */

/* Hier muesst ihr selbst Code vervollstaendigen */ 


#include "user/appl.h"
#include "device/cgastr.h"
#include "machine/plugbox.h"
#include "guard/guard.h"
#include "user/loop.h"
#include "syscall/guarded_organizer.h"
#include "device/watch.h"

#define STACK_SIZE 1024


//Globale Instanzen
CGA_Stream kout;
Plugbox plugbox;
Guard guard;
Guarded_Organizer scheduler;


unsigned char stack1[STACK_SIZE];
unsigned char stack2[STACK_SIZE];

int main()
{
	CPU cpu;
	Watch watch(50000);

	Application appl(stack1+STACK_SIZE);	
	//Loop loop(stack2+STACK_SIZE);
	
	//appl.setKillEntrant(&loop);

	guard.enter();
	scheduler.Scheduler::ready(appl);
	//scheduler.Scheduler::ready(loop);
	
	watch.windup();
	cpu.enable_int();	

	scheduler.schedule();
	
	while(1);
}
