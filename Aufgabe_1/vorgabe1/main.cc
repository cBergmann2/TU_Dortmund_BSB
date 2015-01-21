/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */

/* Hier muesst ihr selbst Code vervollstaendigen */ 

//#include "user/appl_2.h"
#include "user/neuApp.h"
#include "user/appl.h"

#include "device/cgastr.h"
#include "machine/plugbox.h"
#include "guard/guard.h"
#include "user/loop.h"
#include "syscall/guarded_organizer.h"
#include "device/watch.h"
#include "device/keyboard.h"
#include "meeting/bellringer.h"

#define STACK_SIZE 1024


//Globale Instanzen
Keyboard board;
CGA_Stream kout;
Plugbox plugbox;
Guard guard;
Guarded_Organizer scheduler;
Bellringer bellringer;

unsigned char initS[STACK_SIZE];
unsigned char stack1[STACK_SIZE];
unsigned char stack2[STACK_SIZE];

int main()
{
	CPU cpu;
	Watch watch(1000);
	
	Init initProcess(&(initS[0])+STACK_SIZE);
	//Application2 	appl2	(&(stack2[0]) + STACK_SIZE);
	Application 	appl	(&(stack1[0]) + STACK_SIZE);	
	NeuApp 			neuApp 	(&(stack2[0]) + STACK_SIZE);
	

	guard.enter();

	board.plugin();	

	scheduler.Organizer::ready(appl);
	scheduler.Organizer::ready(neuApp);
	scheduler.Organizer::ready(initProcess);
	
	watch.windup();
	cpu.enable_int();	

	scheduler.schedule();
	
	while(1);
}
