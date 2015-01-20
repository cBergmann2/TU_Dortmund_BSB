 #include "thread/init.h"

#include "syscall/guarded_organizer.h"

extern Guarded_Organizer scheduler;

void Init::action ()
{
	while(1)
		scheduler.resume();
}
