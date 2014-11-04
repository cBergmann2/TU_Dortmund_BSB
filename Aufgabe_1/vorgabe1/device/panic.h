/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Standard Unterbrechungsbehandlung.                                        */
/*****************************************************************************/

#ifndef __panic_include__
#define __panic_include__

/* INCLUDES */

#include "guard/gate.h"
#include "machine/cpu.h"

class Panic:public Gate{

private:
    Panic (const Panic &copy); // Verhindere Kopieren

    extern CGA_Stream kout;

public:
    Panic () {}

    void trigger();
          
 };

#endif

