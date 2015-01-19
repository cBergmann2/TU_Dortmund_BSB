/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              W A T C H                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/*****************************************************************************/

#ifndef __watch_include__
#define __watch_include__

/* INCLUDES */

#include "guard/gate.h"
#include "machine/pit.h"
#include "syscall/guarded_organizer.h"
#include "machine/plugbox.h"
#include "machine/pic.h"

/**
 * Die Klasse Watch sorgt für die Behandlung der Zeitgeberunterbrechungen, 
 * indem sie eine Zeitscheibe verwaltet und gegebenenfalls einen 
 * Prozesswechsel auslöst.
 */
class Watch : public Gate, public PIT
 {
private:
    Watch (const Watch &copy); // Verhindere Kopieren

public:
    // WATCH: Initialisiert die Uhr.
    Watch (int us) : PIT (us)
    {
	}

    // WINDUP: "zieht die Uhr auf". Danach laeuft sie los und loest in
    //         regelmaessigen Abstaenden Unterbrechungen aus.
    void windup ();

    // PROLOGUE: Prologue der Uhrenunterbrechung
    bool prologue ();

    // EPILOGUE: Epilogue der Uhrenunterbrechung
    void epilogue ();
 };

#endif
