/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            O _ S T R E A M                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse O_Stream enthaelt die Definition des << Operators fuer die     */
/* wichtigsten der vordefinierten Datentypen und realisiert somit die        */
/* bekannte Ausgabefunktion der C++ IO_Stream Bibliothek. Zur Zeit wird die  */
/* Darstellung von Zeichen, Zeichenketten und ganzen Zahlen unterstuetzt.    */
/* Ein weiterer << Operator erlaubt die Verwendung von Manipulatoren.        */
/*                                                                           */
/* Neben der Klasse O_Stream sind hier auch die Manipulatoren hex, dec, oct  */
/* und bin fuer die Wahl der Basis bei der Zahlendarstellung, sowie endl     */
/* fuer den Zeilenumbruch definiert.                                         */
/*****************************************************************************/

#include "object/o_stream.h"


O_Stream::O_Stream() : Stringbuffer() {
  this->mani = DEC;
}
  
O_Stream::O_Stream(const O_Stream &copy) : 
  Stringbuffer( copy )
{
  //What to do?
}

O_Stream& O_Stream::operator<< (unsigned char c){
    this->put((char)c);
  
    return *this;
}
  
O_Stream& O_Stream::operator<< (char c){

    this->put(c);

    return *this;
}
  
O_Stream& O_Stream::operator<< (unsigned short number){
    guardSem.p();
	switch(mani)
    {
    case BIN:
        convertBin((short)number);
        break;

    case OCT:
        convertValue((long long)number, 8);
        break;

    case DEC:
        convertValue((long long)number);
        break;

    case HEX:
        convertHex((char*)&number, sizeof(short));
        break;
    }

	guardSem.v();
	
    return *this;
}
  
O_Stream& O_Stream::operator<< (short number){
	
	guardSem.p();
	
    switch(mani)
    {
    case BIN:
        convertBin((short)number);
        break;

    case OCT:
        convertValue((long long)number, 8);
        break;

    case DEC:
        convertValue((long long)number);
        break;

    case HEX:
        convertHex((char*)&number, sizeof(short));
        break;
    }
	guardSem.v();
    return *this;
}
  
O_Stream& O_Stream::operator<< (unsigned int number){

	guardSem.p();
	
    switch(mani)
    {
    case BIN:
        convertBin((int)number);
        break;

    case OCT:
        convertValue((long long)number, 8, true);
        break;

    case DEC:
        convertValue((long long)number);
        break;

    case HEX:
        convertHex((char*)&number, sizeof(int));
        break;
    }
	
	guardSem.v();

    return *this;
}
  
O_Stream& O_Stream::operator<< (int number){

	guardSem.p();
	
    switch(mani)
    {
      case BIN:
        convertBin((int)number);
        break;

    case OCT:
        convertValue((long long)number, 8, true);
        break;

    case DEC:
        convertValue((long long)number);
        break;

    case HEX:
        convertHex((char*)&number, sizeof(int));
        break;
    }
	
	guardSem.v();
	
    return *this;
}
  
O_Stream& O_Stream::operator<< (unsigned long number){
    guardSem.p();
	
	switch(mani)
    {
      case BIN:
        convertBin((long)number);
        break;

    case OCT:
        convertValue((long long)number, 8);
        break;

    case DEC:
        convertValue((long long)number);
        break;

    case HEX:
        convertHex((char*)&number, 4);
        break;
    }

	guardSem.v();
	
    return *this;
}
  
O_Stream& O_Stream::operator<< (long number){

	guardSem.p();

    switch(mani)
    {
    case BIN:
        convertBin((long)number);
        break;

    case OCT:
        convertValue((long long)number, 8);
        break;

    case DEC:
        convertValue((long long)number);
        break;

    case HEX:
        convertHex((char*)&number, 4);
        break;
    }
	
	guardSem.v();
	
    return *this;
}
  

//Hexadezimale anzeige eines void-Zeigers
O_Stream& O_Stream::operator<< (void* pointer){

	guardSem.p();
	
    convertHex((char*)&pointer, sizeof(void*));
	
	guardSem.v();
	
    return *this;
}
  

//NTString einfügen
O_Stream& O_Stream::operator<< (char* text){
    guardSem.p();
	
	while(*text)
        put(*(text++));
		
	guardSem.v();
	
    return *this;
}
  

//Manipulatorfunktion
O_Stream& O_Stream::operator<< (O_Stream& (*fkt)(O_Stream&)){
    return (*fkt)(*this);
}

void O_Stream::convertBin(short number){
    unsigned short comp = (1<<15);
    char temp = 0 ;
    bool active = false;

    do
    {
        temp = (number&comp)?'1':'0';
        comp = comp>>1;
        if(!active)
        {
            if(temp=='1')
                active=true;
            else
                continue;
        }
       this->put(temp);

    }while(comp>0);
}

void O_Stream::convertBin(int number){
    unsigned int comp = (1<<(sizeof(int)*8-1));
    char temp = 0 ;
    bool active = false;

    do
    {
        temp = (number&comp)?'1':'0';
        comp = comp>>1;
        if(!active)
        {
            if(temp=='1')
                active=true;
            else
                continue;
        }
       this->put(temp);

    }while(comp>0);
}

void O_Stream::convertBin(long number){
    unsigned long comp = (1<<31);
    char temp = 0 ;
    bool active = false;

    do
    {
        temp = (number&comp)?'1':'0';
        comp = comp>>1;
        if(!active)
        {
            if(temp=='1')
                active=true;
            else
                continue;
        }
       this->put(temp);

    }while(comp>0);
}

void O_Stream::convertHex(char *numberptr, char size)
{
    char zeichen[2];
    numberptr+=size;
    do
    {
        convertHex(*(--numberptr), &(zeichen[0]));
        this->put(zeichen[0]);
        this->put(zeichen[1]);
        size--;
    }while(size>0);
}

/**
 * Convertiert ein Byte in Hex-Darstellung.
 * result muss auf einen 2-Byte großen Speicherbereich zeigen
 */
void O_Stream::convertHex(char value, char *result){
    if(!result) return;
    char temp;

    temp = (value&0x0F);
    if(temp > 9)
        temp+=55;
    else
        temp+='0';
    result[1] = temp;

    temp = (value&0xF0)>>4;
    if(temp > 9)
        temp+=55;
    else
        temp+='0';
    *result = temp;
}

void O_Stream::convertValue(long long value, unsigned int base, bool isUnsigned)
{
    char array[32];
    char *ptr = &(array[0]);
    char *end = &(array[32]);
    long temp;

    if((isUnsigned==false) && (value<0)) {        
	put('-');
        value*=-1;
    }
	 
    temp = (long long) value;
    do
    {
        *ptr = (temp%base)+'0';
	ptr++;
        temp=temp/base;
    }while(temp && ptr!=end);

    putReverseString(&(array[0]), ptr-1);
}

void O_Stream::putReverseString(char *string, char *first){
    string--;   //Endbedingung
    while(string!=first)
    {
        put(*(first--));
    }
}

void O_Stream::setManipulator(manipulation manipulator){
    this->mani = manipulator;
}
  
O_Stream& endl(O_Stream& os){
    os.put('\n');
    return os;
}
  
O_Stream& bin(O_Stream& os){
    os.setManipulator(BIN);
    return os;
}
  
O_Stream& oct(O_Stream& os){
    os.setManipulator(OCT);
    return os;
}
  
O_Stream& dec(O_Stream& os){
    os.setManipulator(DEC);
    return os;
}
  
O_Stream& hex(O_Stream& os){
    os.setManipulator(HEX);
    return os;
}
  
