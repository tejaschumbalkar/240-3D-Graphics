# Interfacing-LCD-LPCXpresso-1769-SPI
Interfacing Graphic LCD with LPCXpresso 1769 Using SPI and generate 2D graphics

Algorithm

Algorithm to display rotating square:
1. Initial square is drawn using drawLine() function provided by the graphic library of Adafruit LCD display.
2. The coordinates of the second square is calculated using mathematical equation: P = P0 + lamda * (P1 – P0).
3. Using the coordinates, the square is drawing using drawLine() function.
4. The program is then set in a recursion to display a pattern of rotating shrinking squares of 11 levels.

Algorithm to display rotating triangle:
1. Initial triangle is drawn using drawLine() function provided by the graphic library of Adafruit LCD display.
2. The coordinates of the second triangle is calculated using mathematical equation: P = P0 + lamda * (P1 – P0).
3. Using the coordinates, the triangle is drawing using drawLine() function.
4. The program is then set in a recursion to display a pattern of rotating shrinking triangles of 11 levels.

Algorithm to display tree pattern:
1. Initial bark of the tree is drawn using drawLine() function.
2. From the end point of the bark line, 3 branches are drawn with a constant angle.

Pseudo Code
 
// Function to initialize LCD 
void lcd_init(){
initialize portnumber = 1;
set output as SSP0 P0.6;
set D/C as P0.21;
set RESET as P0.22;
for ( i = 0; i < SSP_BUFSIZE; i++ )	
/* Init RD and WR buffer */
	    {
	  	  src_addr[i] = 0;
	  	  dest_addr[i] = 0;
	    }

	
	 /* Sleep out */
	 SSP_SSELToggle( portnum, 0 );
	 src_addr[0] = 0x11;	/* Sleep out */
	 SSPSend( portnum, (uint8_t *)src_addr, 1 );
	 SSP_SSELToggle( portnum, 1 );

	 lcddelay(200);
	/* delay 200 ms */
	/* Display on */
	 SSP_SSELToggle( portnum, 0 );
	 src_addr[0] = 0x29;	/* Disp On */
	 SSPSend( portnum, (uint8_t *)src_addr, 1 );
	 SSP_SSELToggle( portnum, 1 );
	 lcddelay(200);
}



//Main Function

int main(int)
{
SSP1Init();
 //SPI initialize
lcd_init();
 //LCD initialize
//fill the lcd with black color;
//draw initial square using drawLine() function;
lcddelay(200);
rotating_mysquare(0,126,126,0,0,0,126,126);
 //rotating squares using recursion
lcddelay(200);
fill the lcd with black color;
draw initial triangle;
rotating_mytriangle(63,126,0,0,158,158); 
//rotating triangles

lcddelay(500);
fill the lcd with black color;
draw_myline(64,100,64,160,GREEN);
 //tree trunk_1
grow_mytree(64,100,5.23,20,7,GREEN); 
//right branch (angle = 5.23 rad/300 deg)
grow_mytree(64,100,4.18,20,7,GREEN); 
//left branch (angle = 4.18 rad/240 deg)
grow_mytree(64,100,4.71,20,7,GREEN); 
//center branch (angle = 4.71 rad/0 deg)
  return 0;
}
