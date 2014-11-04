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
#include "device/cgastr.h"
#include "guard/gate.h"
#include "machine/cpu.h"

class Panic:public Gate{

private:
    Panic (const Panic &copy); // Verhindere Kopieren

    

public:
    Panic ();

    void trigger();
          
 };

#endif

