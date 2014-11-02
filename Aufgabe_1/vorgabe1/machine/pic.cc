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


PIC::PIC(const PIC &copy) // Verhindere Kopieren
{
    
}


/* 
* Lässt zu, dass der PIC Unterbrechungen des Geräts 
* Nummer interrupt_device an den Prozessor weiterleitet.
*/
void PIC::allow (int interrupt_device)
{
    
}


/*
* Verhindert, dass der PIC Unterbrechungen des Geräts 
* Nummer interrupt_device an den Prozessor weiterleitet.
*/
void PIC::forbid (int interrupt_device)
{
  
}
  