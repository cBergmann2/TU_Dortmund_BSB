/* $Id: main.cc 956 2008-10-19 22:24:23Z hsc $ */

/* Hier muesst ihr selbst Code vervollstaendigen */ 

#include "user/loop.h"
#include "user/neuApp.h"
#include "user/appl.h"
#include "user/appl2.h"

#include "machine/plugbox.h"

#include "guard/guard.h"

#include "syscall/guarded_organizer.h"
#include "syscall/guarded_buzzer.h"

#include "device/watch.h"
#include "device/keyboard.h"
#include "device/cgastr.h"

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
unsigned char stack3[STACK_SIZE];
unsigned char stack4[STACK_SIZE];
unsigned char stack5[STACK_SIZE];


int main()
{
	CPU cpu;
	Watch watch(1000);	//1ms Zyklen
	
	Init 			initProcess		(&(initS[0])+STACK_SIZE);
	Application 	appl			(&(stack1[0]) + STACK_SIZE);	
	NeuApp 			neuApp 			(&(stack2[0]) + STACK_SIZE);
	Loop			loop			(&(stack3[0]) + STACK_SIZE);
	Appl_2			appl2_1			(&(stack4[0]) + STACK_SIZE);
	Appl_2			appl2_2			(&(stack5[0]) + STACK_SIZE);
	
	Guarded_Buzzer buzzer;
	appl2_1.registerBuzzer(&buzzer, true);
	appl2_2.registerBuzzer(&buzzer, false);
	
	guard.enter();

	board.plugin();	

	scheduler.ready(appl);
	scheduler.ready(neuApp);
	scheduler.ready(initProcess);
	scheduler.ready(loop);
	scheduler.ready(appl2_1);
	scheduler.ready(appl2_2);
	
	watch.windup();
	cpu.enable_int();	

	scheduler.schedule();
	
	while(1);
}
