#ifndef __screen_include__
#define __screen_include__

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

#include "machine/io_port.h"

#define VIDEO_MEM_START 0xb800
#define CURSOR_POS_HIGH 14
#define CURSOR_POS_LOW 15
#define ATTRIB_BLACK_WHITE 0x0f

class CGA_Screen
 {
private:
	IO_Port indexregister(0x3d4);
	IO_Port datenregister(0x3d5);

	void moveLinesUp(void);

	CGA_Screen(const CGA_Screen &copy); // Verhindere Kopieren
public:
	CGA_Screen();
   
	void show (int x, int y, char c, unsigned char attrib);
   
	void setpos (int x, int y);
	
	void getpos (int &x, int &y);
   
	void print (char* text, int length, unsigned char attrib);
};

#endif

