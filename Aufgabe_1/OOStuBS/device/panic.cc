/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Standard Unterbrechungsbehandlung.                                        */
/*****************************************************************************/

 
Panic::Panic(){

}

void Gate::trigger(){
	//Fehlermeldung anhalten
	kout << "Fehler: Interrupt eingetreten der von keiner ISR beahndelt wird!\n";
	kout << "->System wird angehlaten";

	//System anhalten
}
