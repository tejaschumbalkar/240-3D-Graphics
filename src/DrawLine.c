//Draw Single-Line

/*
 ===============================================================================
 Description : World-to-viewer coordinate system
 ===============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cr_section_macros.h>
#include <NXP/crp.h>
#include "LPC17xx.h"
#include "ssp.h"
#include "LPC17xx.h"       /* LPC17xx definitions */
#include "ssp.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "font.h"
#include "extint.h"
struct coordinates{
	int x;
	int y;
};

uint8_t src_addr[SSP_BUFSIZE];
uint8_t dest_addr[SSP_BUFSIZE];


#define ST7735_TFTWIDTH 127
#define ST7735_TFTHEIGHT 159

#define ST7735_CASET 0x2A
#define ST7735_RASET 0x2B
#define ST7735_RAMWR 0x2C
#define ST7735_SLPOUT 0x11
#define ST7735_DISPON 0x29

#define swap(x, y) {x = x + y; y = x - y; x = x - y ;}
#define BLUE    0x0000FF
#define CYAN 0x0007FF
#define RED 0xFF0000
#define MAGENTA 0x00F81F
#define WHITE 0xFFFFFF
#define PURPLE 0xCC33FF
#define YELLOW 0x00FFE0
#define GREEN 0x00FF00
#define BROWN 0x000033
#define SKYBLUE 0xffb266
#define BLACK 0x000000
#define ORANGE  0xFF8000
#define LTBLUE  0x9090FF
#define OLIVE   0x808000


int _height = ST7735_TFTHEIGHT;
int _width = ST7735_TFTWIDTH;

#define LCD_D_C				23
#define LCD_RST				24
#define LCD_CS				16

#define PORT_NUM 0
float lambda = 0.8;
float lambda1 = 0.2;




uint32_t returnColour(int option) {

	uint32_t colour;
	switch(option) {
	case 0:
	  colour = BLACK;
	  break;
	case 1:
	  colour = WHITE;
	  break;
	case 2:
	  colour = RED;
	  break;
	case 3:
	  colour = GREEN;
	  break;
	case 4:
	  colour = BLUE;
	  break;
	case 5:
	  colour = YELLOW;
	  break;
	case 6:
	  colour = CYAN;
	  break;
	case 7:
	  colour = MAGENTA;
	  break;
	case 8:
	  colour = PURPLE;
	  break;
	case 9:
	  colour = ORANGE;
	  break;
	case 10:
	  colour = OLIVE;
	  break;
	case 11:
	  colour = LTBLUE;
	  break;
	case 12:
	  colour = BROWN;
	  break;
	default:
	  colour = BLACK;
	  break;
	}
	return colour;
}

struct world{
	int x;
	int y;
}sW;

struct camera{
	int xe;
	int ye;
	int ze;
}sCam;

struct Location{
   int x;
   int y;
}loc;

/*
 ** Descriptions: Draw line function
*/
void writecommand(uint8_t c) {
	LPC_GPIO0->FIOCLR |= (0x1 << LCD_D_C);
	spiwrite(c);
}

void writedata(uint8_t c) {
	LPC_GPIO0->FIOSET |= (0x1 << LCD_D_C);
	spiwrite(c);
}

void writeword(uint16_t c) {
	uint8_t d;
	d = c >> 8;
	writedata(d);
	d = c & 0xFF;
	writedata(d);
}

void write888(uint32_t color, uint32_t repeat) {
	uint8_t red, green, blue;
	int i;
	red = (color >> 16);
	green = (color >> 8) & 0xFF;
	blue = color & 0xFF;
	for (i = 0; i < repeat; i++) {
		writedata(red);
		writedata(green);
		writedata(blue);
	}
}

void setAddrWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) {
	writecommand(ST7735_CASET);
	writeword(x0);
	writeword(x1);
	writecommand(ST7735_RASET);
	writeword(y0);
	writeword(y1);
}
void lcddelay(int ms) {
	int count = 24000;
	int i;
	for (i = count * ms; i--; i > 0)
		;
}


/**************************
 **" Main Function main()
 **************************/
int main(void)
{
	SSP1Init();
	lcddelay(2000);
	LPC_GPIO0->FIODIR |= (1<<25);
	LPC_GPIO0->FIOPIN &= ~(1<<25);
		LPC_GPIO0->FIOPIN |= (1<<25);
		printf("Sent : %c		Received: %c\n",'*',SSP1SendReceive('*'));
		lcddelay(100);
		printf("Sent : %c		Received: %c\n",'h',SSP1SendReceive('h'));
		lcddelay(100);
		LPC_GPIO0->FIOPIN &= ~(1<<25);
		lcddelay(1000); //delay for 10 seconds
	return 0;
}
