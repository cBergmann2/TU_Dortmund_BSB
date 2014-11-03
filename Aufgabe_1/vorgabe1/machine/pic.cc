/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I C                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interrupt Controller.                                        */
/* Mit Hilfe des PICs koennen Hardware-Unterbrechungen einzeln zugelassen    */
/* oder unterdrueckt werden. Auf diese Weise wird also bestimmt, ob die      */
/* Unterbrechung eines Geraetes ueberhaupt an den Prozessor weitergegeben    */
/* wird. Selbst dann erfolgt eine Aktivierung der Unterbrechungsroutine nur, */
/* wenn der Prozessor bereit ist, auf Unterbrechungen zu reagieren. Dies     */
/* kann mit Hilfe der Klasse CPU festgelegt werden.                          */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "machine/pic.h"

PIC::PIC() :
      master(0x21), 
      slave(0xa1)
{
  
}

PIC::PIC(const PIC &copy) :// Verhindere Kopieren
      master(0x21), 
      slave(0xa1)
{
    
}


/* 
* Lässt zu, dass der PIC Unterbrechungen des Geräts 
* Nummer interrupt_device an den Prozessor weiterleitet.
*/
void PIC::allow (int interrupt_device)
{
    int maske=0;
    IO_Port *access;
    
    //Interrupt_device prüfen
    //master oder slave?
    if(interrupt_device <= 7)
    {
      //master
      access = &master;
    }else{
      //slave
      access = &slave;
      interrupt_device-=8;
    }
      
    //aktuelle maske 
    maske = access->inb();
    
    //neue maske berechnen (Bit löschen)
    maske &= ~(1<<interrupt_device);
    
    //maske aktualisieren
    access->outb(maske);
}


/*
* Verhindert, dass der PIC Unterbrechungen des Geräts 
* Nummer interrupt_device an den Prozessor weiterleitet.
*/
void PIC::forbid (int interrupt_device)
{
    int maske=0;
    IO_Port *access;
    
    //Interrupt_device prüfen
    //master oder slave?
    if(interrupt_device <= 7)
    {
      //master
      access = &master;
    }else{
      //slave
      access = &slave;
      interrupt_device-=8;
    }
      
    //aktuelle maske 
    maske = access->inb();
    
    //neue maske berechnen (Bit setzen)
    maske |= (1<<interrupt_device);
    
    //maske aktualisieren
    access->outb(maske);
}
  
