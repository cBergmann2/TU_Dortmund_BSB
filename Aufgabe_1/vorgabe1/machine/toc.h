/* $Id: toc.h 956 2008-10-19 22:24:23Z hsc $ */

/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 T O C                                     */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Struktur toc dient dazu, bei einem Koroutinenwechsel die Werte der    */
/* nicht-fluechtigen Register zu sichern.                                    */
/* Beim GNU C Compiler sind eax, ecx und edx fluechtige Register, die bei    */
/* Funktionsaufrufen und somit auch bei einem Koroutinenwechsel keine        */
/* spaeter noch benoetigten Werte haben duerfen. Daher muss in der Struktur  */
/* toc auch kein Platz fuer sie bereitgestellt werden.                       */
/*                                                                           */
/* Achtung: Fuer den Zugriff auf die Elemente von struct toc aus einer       */
/* Assemblerfunktion heraus werden in der Datei toc.inc Namen fuer die       */
/* benoetigten Abstaende der einzelnen Elemente zum Anfang der Struktur      */
/* definiert. Damit dann auch auf die richtigen Elemente zugegriffen wird,   */
/* sollten sich die Angaben von toc.h und toc.inc exakt entsprechen.         */
/* Wer also toc.h aendert, muss auch toc.inc anpassen (und umgekehrt.)       */
/*****************************************************************************/

#ifndef __toc_include__
#define __toc_include__

// TOC: ("thread of control")
//
struct toc
 {
      void *ebx;
      void *esi;
      void *edi;
      void *ebp;
      void *esp;
 };
 


/**
 * Diese Funktion bereitet die Struktur toc f�r die erste Aktivierung vor. 
 * Dazu m�ssen Registerinhalte und Stack so initialisiert werden, dass 
 * bei der ersten Aktivierung die Ausf�hrung mit der Funktion kickoff beginnt, 
 * die wiederum den Zeiger object als ersten Parameter auf dem Stack vorfinden muss. 
 */
void toc_settle (struct toc* regs, void* tos, void (*kickoff)(void*), void* object);



/**
 * Diese Funktion l�dt die Prozessorregister mit den Inhalten der Struktur regs.
 */
void toc_go (struct toc* regs);


/**
 * Diese Funktion f�hrt einen Kontextwechsel durch. Dazu brauchen 
 * nur die aktuellen Registerwerte in regs_now gesichert und durch 
 * die Werte von regs_then ersetzt werden. 
 */
void toc_switch (struct toc* regs_now, struct toc* regs_then);


#endif
