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

#ifndef __pic_include__
#define __pic_include__

#include "machine/io_port.h"

enum{
  timer = 0,
  keyboard = 1,
  kaskadierung = 2,
  com_2 = 3,
  com_1 = 4,
  floppy = 6,
  lpt_1 = 7,
  cmos_clock = 8,
  PS2 = 12,
  numCoPro = 13,
  ide_1 = 14,
  ide_2 = 15
  
};

class PIC
 {
private:
    PIC(const PIC &copy); // Verhindere Kopieren
public:
    PIC();
    
    
    /* 
     * Lässt zu, dass der PIC Unterbrechungen des Geräts 
     * Nummer interrupt_device an den Prozessor weiterleitet.
     */
    void allow (int interrupt_device);
    
    /*
     * Verhindert, dass der PIC Unterbrechungen des Geräts 
     * Nummer interrupt_device an den Prozessor weiterleitet.
     */
    void forbid (int interrupt_device);
    

 private:
   
  IO_Port master, slave;


 };

#endif
