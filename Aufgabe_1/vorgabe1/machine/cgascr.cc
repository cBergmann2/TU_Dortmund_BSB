/* $Id: cgascr.cc 5834 2013-10-08 17:04:08Z os $ */

/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             C G A _ S C R E E N                           */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe dieser Klasse kann man auf den Bildschirm des PCs zugreifen.    */
/* Der Zugriff erfolgt direkt auf der Hardwareebene, d.h. ueber den Bild-    */
/* schirmspeicher bzw. die I/O-Ports der Grafikkarte.                        */
/*****************************************************************************/

#include "machine/cgascr.h"

CGA_Screen::CGA_Screen(const CGA_Screen &copy)
{

}

CGA_Screen::CGA_Screen()
{
	char* ptr;

	ptr=(char*)VIDEO_MEM_START;

	
	//Bildschirm init (Leerzeichen schreiben)
	for(int i=0; i<25; i++)		
	{
		for(int j=0; j<160; j++)	
		{
			*(ptr_trgt+2*(j+80*i)) = ' ';
			*(ptr_trgt+2*(j+80*i)+1) = ATTRIB_BLACK_WHITE;
		}
	}
}

//-------------------------------------------------------------------------------
// Diese Methode gibt das Zeichen c an der Position (x,y) mit dem angegebenen 
// Farbattribut attrib aus. Dabei gibt x die Spalte und y die Zeile der 
// gewünschten Position an, wobei gilt: 0<=x<=79 und 0<=y<=24. Die Position (0,0) 
// bezeichnet die linke obere Ecke des Bildschirms. Mit attrib lassen sich 
// Merkmale wie Hintergrundfarbe, Vordergrundfarbe und Blinken festlegen
//-------------------------------------------------------------------------------
void CGA_Screen::show(int x, int y, char c, unsigned char attrib)
{
	char* pos;

	pos=(char*) VIDEO_MEM_START+2*(x+y*80);	//gehe zu x/y in video ram
	*pos=c;									//schreibe zeichen an erstes byte
	*(pos+1)=attrib;						//attribut an zweites byte

	return;
}

//-------------------------------------------------------------------------------
// Diese Methode setzt den Cursor an die angegebene Position
//-------------------------------------------------------------------------------
void CGA_Screen::setpos(int x, int y)
{
	unsigned short zeichenoffset=0;

	zeichenoffset=x+y*80;						//an welcher bildschirmposition der cursor stehen soll (80*25 stk)

	this->indexregister.outb(CURSOR_POS_LOW);					//indexregister=15
	this->datenregister.outb(zeichenoffset);			//schreibe lowbyte
	
	zeichenoffset=(zeichenoffset>>8);	//schiebe highbyte auf lowbyte stelle, alles null bis auf lowbyte

	this->indexregister.outb(CURSOR_POS_HIGH);					//indexregister=14
	this->datenregister.outb(zeichenoffset);			//schreibe highbyte

	return;
}

//-------------------------------------------------------------------------------
// Hiermit kann die aktuelle Position des Cursors von der Grafikkarte abgefragt 
// werden. x und y sind Referenzen und dienen als Ausgabeparameter
//-------------------------------------------------------------------------------
void CGA_Screen::getpos(int &x, int &y)
{
	int lowbyte=0, highbyte=0;
	unsigned short zeichenoffset=0;

	this->indexregister.outb(CURSOR_POS_LOW);					//indexregister=15 (lowbyte)
	this->lowbyte=datenregister.inb();

	this->indexregister.outb(CURSOR_POS_HIGH);				//indexregister=14 (highbyte)
	this->highbyte=datenregister.inb();

	zeichenoffset=(unsigned short) highbyte;
	zeichenoffset=(zeichenoffset<<8) & 0xff00;			//highbyte auf richtige position, lowbyte nullen

	zeichenoffset=zeichenoffset | lowbyte;

	x=(int) (zeichenoffset % 80);
	y=(int) ((float)zeichenoffset / 80.0);							//nachkommastellen abschneiden

	return;
}
   
//-------------------------------------------------------------------------------
// Mit dieser Methode kann eine Zeichenkette text der Laenge length ausgegeben 
// werden, wobei an der aktuellen Position des Cursors begonnen wird.
// Nach Abschluss der Ausgabe soll der Cursor hinter dem zuletzt ausgegebenen Zeichen stehen.
// Der gesamte text soll einheitlich mit den durch attrib gewählten Farben dargestellt werden.
// Wenn bis zum Ende der Zeile nicht mehr genügend Platz ist, soll die Ausgabe auf der folgenden 
// Zeile fortgesetzt werden. Sobald die letzte Bildschirmzeile gefüllt ist, soll der gesamte 
// Bildschirmbereich um eine Zeile nach oben geschoben werden. Dadurch verschwindet die erste Zeile. 
// Dafür kann nun die letzte Zeile erst gelöscht und dann die Ausgabe dort fortgesetzt werden.
// Ein Zeilenumbruch muss auch erfolgen, wann immer das Zeichen '\n' im auszugebenen Text enthalten ist.
//-------------------------------------------------------------------------------
void CGA_Screen::print(char* text, int length, unsigned char attrib)
{
	int x=0, y=0;

	this->getpos(x, y);			//Hole aktuelle Position des cursors

	for(int i=0; i<length; i++;)
	{
		
		this->show(x, y, *(text+i), attrib);	//Schreibe fortlaufend an Position
		x++;	//nächste Bildschirmposition in Zeile

		if((y == 24) && (x == 80)) //Bildschirm voll
		{
			this->moveLinesUp();		//verschiebe Zeilen um eins nach oben -> erste Zeile verschwindet, leere letzte Zeile
			x=0;						//erstes Element letzte Zeile
		}
		else if(x == 80) //letztes Element der Zeile
		{
			y++;			//nächste Zeile
			x=0;			//erstes Element
		}
		
		this->setpos(x, y);	//Cursor eine Bildschirmposition weitersetzen
	}

	//Bildschirm voll -> erste Zeile Löschen, zweite zeile = erste zeile, dritte zeile = zweite zeile etc. (die werte um -80*2 byte verschieben)

	return;
}


//Bildschirm voll -> erste Zeile Löschen, zweite zeile = erste zeile, dritte zeile = zweite zeile etc. (die werte um -80*2 byte verschieben)
void CGA_Screen::moveLinesUp(void)
{
	char* ptr_old;
	char* ptr_new;

	ptr_trgt=(char*)VIDEO_MEM_START;		//erste Zeile
	ptr_src=(char*)(VIDEO_MEM_START+80);	//zweite Zeile

	for(int i=0; i<24; i++)		//24 mal Zeilen kopieren
	{
		for(int j=0; j<160; j++)	//160 bytes pro Zeile kopieren
		{
			*(ptr_trgt+j+160*i)=*(ptr_src+j+160*i);
		}
	}

	for(int i=0; i<80; i++)
	{
		this->show(i, 24, ' ', ATTRIB_BLACK_WHITE);		//letzte Zeile mit Leerzeichen aufüllen
	}

	return;
}