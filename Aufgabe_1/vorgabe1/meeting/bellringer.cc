/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          B E L L R I N G E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Der "Gloeckner" wird im Rahmen der Timer-Epilog Bearbeitung aktiviert.    */
/* Er prueft, ob irgendwelche Glocken (Bell-Objekte) laeuten muessen. Die    */
/* Glocken befinden sich in einer Queue, die der Gloeckner verwaltet.        */
/*****************************************************************************/

#include "meeting/bellringer.h"


/**
 * Prüft, ob Glocken zu läuten sind und tut es gegebenenfalls.
 */
void Bellringer::check ()
{

}

/**
 * Die Glocke bell wird dem Glöckner überantwortet. Sie soll nach ticks Zeiteinheiten geläutet werden.
 */
void Bellringer::job (Bell *bell, int ticks)
{

}
	
	
/**
 * Die Glocke bell soll nun doch nicht geläutet werden. 
 */
void Bellringer::cancel (Bell *bell)
{

}