/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               L O C K E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Locker implementiert eine Sperrvariable, die verwendet wird,   */
/* um kritische Abschnitte zu schuetzen. Die Variable zeigt allerdings nur   */
/* an, ob der kritische Abschnitt frei ist. Ein eventuelles Warten und der   */
/* Schutz der fuer diese Klasse notwendigen Zaehlfunktion muss ausserhalb    */
/* erfolgen.                                                                 */
/*****************************************************************************/

/*****************************************************************************
 * Die Methoden der Klasse sind so kurz, dass sie am besten inline 
 * definiert werden sollten. 
 *****************************************************************************/

#ifndef __Locker_include__
#define __Locker_include__

class Locker
{
private:
	Locker(const Locker &copy); // Verhindere Kopieren
	/* Hier muesst ihr selbst Code vervollstaendigen */ 

public:

	//Initialisiert die Sperrvariable so, dass der kritische Abschnitt als frei markiert wird.
	Locker () :
		available(true)
	{
		
	}

	//Diese Methode muss aufgerufen werden, wenn der kritische Abschnitt betreten wird.
	void enter ()
	{
		available = false;
	}

	//Mit dieser Methode wird der kritische Abschnitt wieder verlassen.
	void retne ()
	{
		available = true;
	}

	//Diese Methode gibt an, ob der kritische Abschnitt frei ist.
	bool avail ()
	{
		return available;
	}
	
private:
	bool available;

};

#endif
