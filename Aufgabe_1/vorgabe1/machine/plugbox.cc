/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              P L U G B O X                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Abstraktion einer Interruptvektortabelle. Damit kann man die Behandlungs- */
/* routine fuer jeden Hardware-, Softwareinterrupt und jede Prozessor-       */
/* exception festlegen.                                                      */
/*****************************************************************************/

/**
 * Setzt für alle Unterbrechungen und Ausnahmen das global bekannte Panic-Objekt panic.
 * Dieses Objekt stellt eine minimale Unterbrechungsbehandlung sicher.
 *
 */
Plugbox::Plugbox(){

	//Standard ISR
	Panic panic;

	//Interrupt-Vektor-Tabelle initialisieren
	for(int i=0;i<64;i++){

		this->assign(i, panic);
	}
}

/**
 * Ordnet eine Unterbrechungsbehandlung vom Typ Gate einem Slot zu
 */
void Plugbox::assign(unsigned int slot, Gate &gate){
	this->interruptTabelle[slot] = gate;
}

/**
 * Liefert das Gate, dass dem Slot slot zugeordnet ist.
 */
Gate& Plugbox::report(unsigned int slot){
	return this->interruptTabelle[slot];
}
