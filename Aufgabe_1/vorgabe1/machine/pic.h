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
  timer = 0;
  keyboard = 1;
};

class PIC
 {
private:
    PIC(const PIC &copy); // Verhindere Kopieren
public:
    PIC() {}
    
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
   
  


 };

#endif
