/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                G U A R D                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe dieser Klasse koennen Aktivitaeten, die einen kritischen        */
/* Abschnitt betreffen, der mit einem Guard-Objekt geschuetzt ist, mit       */
/* Unterbrechungsbehandlungsroutinen synchronisiert werden, die ebenfalls    */
/* auf den kritischen Abschnitt zugreifen.                                   */
/*****************************************************************************/

#include "guard/guard.h"

Guard::Guard () : 
  Locker()
{
  
}

/**
  * Mit dieser Methode wird der kritische Abschnitt verlassen und 
  * die angestauten Epiloge werden abgearbeitet.
  */
void Guard::leave ()
{
  
}
  
/**
  * Diese Methode wird von guardian () aufgerufen, falls der zuvor 
  * ausgeführte Prolog durch einen Rückgabewert true angezeigt hat, 
  * dass sein Epilog ausgeführt werden soll. Ob der Epilog sofort 
  * behandelt oder zunächst nur in die Epilogliste eingehängt wird, 
  * hängt davon ab, ob der kritische Abschnitt frei oder besetzt ist.   
  */   
void Guard::relay (Gate* item)
{
  
}