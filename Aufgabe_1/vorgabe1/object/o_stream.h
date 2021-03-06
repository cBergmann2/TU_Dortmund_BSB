/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            O _ S T R E A M                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse O_Stream enthaelt die Definition des << Operators fuer die     */
/* wichtigsten der vordefinierten Datentypen und realisiert somit die        */
/* bekannte Ausgabefunktion der C++ iO_Stream Bibliothek. Zur Zeit wird die  */
/* Darstellung von Zeichen, Zeichenketten und ganzen Zahlen unterstuetzt.    */
/* Ein weiterer << Operator erlaubt die Verwendung von Manipulatoren.        */
/*                                                                           */
/* Neben der Klasse O_Stream sind hier auch die Manipulatoren hex, dec, oct  */
/* und bin fuer die Wahl der Basis bei der Zahlendarstellung, sowie endl     */
/* fuer den Zeilenumbruch definiert.                                         */
/*****************************************************************************/

#ifndef __o_stream_include__
#define __o_stream_include__

#include "object/strbuf.h"

#ifdef DEBUG_OBJECT
#include <qdebug.h>
#include <qstring.h>
#endif


typedef enum {
    BIN,
    OCT,
    DEC,
    HEX
} manipulation;

class O_Stream : public Stringbuffer
{
public:
    O_Stream();
  
private:
    O_Stream(const O_Stream &copy); // Verhindere Kopieren

public:
    O_Stream& operator<< (unsigned char c);
    O_Stream& operator<< (char c);
    O_Stream& operator<< (unsigned short number);
    O_Stream& operator<< (short number);
    O_Stream& operator<< (unsigned int number);
    O_Stream& operator<< (int number);
    O_Stream& operator<< (unsigned long number);
    O_Stream& operator<< (long number);

    //Hexadezimale anzeige eines void-Zeigers
    O_Stream& operator<< (void* pointer);

    //NTString einfügen
    O_Stream& operator<< (char* text);

    //Manipulatorfunktion
    O_Stream& operator<< (O_Stream& (*fkt)(O_Stream&));

    void setManipulator(manipulation manipulator);
  
#ifdef DEBUG_OBJECT
    void print(){
        QString s;
        for(int i=0; i<=count; i++)
        {
            s.append(buffer[i]);
        }
        qDebug() << s;
    }
#endif

private:
    manipulation mani;

    void convertBin(short number);
    void convertBin(int number);
    void convertBin(long number);

    void convertHex(char value, char *result);
    void convertHex(char* numberptr, char size);

    void convertValue(long long value, unsigned int base=10, bool isUnsigned=false);
    void putReverseString(char *string, char *first);

};
   
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          M A N I P U L A T O R E N                        */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die folgenden Funktionen erhalten und liefern jeweils eine Referenz auf   */
/* ein O_Stream Objekt. Da die Klasse O_Stream einen Operator << fuer        */
/* derartige Funktionen definiert, koennen sie mit Hilfe dieses Operators    */
/* aufgerufen und sogar in weitere Eingaben eingebettet werden.              */
/* Aufgabe der Manipulatoren ist, die Darstellung der nachfolgenden Ausgaben */
/* zu beeinflussen, z.B durch die Wahl des Zahlensystems.                    */
/*---------------------------------------------------------------------------*/

// ENDL: fuegt einen Zeilenumbruch in die Ausgabe ein.
/* Hier muesst ihr selbst Code vervollstaendigen */ 

// BIN: waehlt das binaere Zahlensystem aus.
/* Hier muesst ihr selbst Code vervollstaendigen */ 
        
// OCT: waehlt das oktale Zahlensystem aus.
/* Hier muesst ihr selbst Code vervollstaendigen */ 
        
// DEC: waehlt das dezimale Zahlensystem aus.
/* Hier muesst ihr selbst Code vervollstaendigen */ 
        
// HEX: waehlt das hexadezimale Zahlensystem aus.
/* Hier muesst ihr selbst Code vervollstaendigen */ 
  

O_Stream& endl(O_Stream& os);
O_Stream& bin(O_Stream& os);
O_Stream& oct(O_Stream& os);
O_Stream& dec(O_Stream& os);
O_Stream& hex(O_Stream& os);

#endif

