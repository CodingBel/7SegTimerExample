#include <p18f4520.h>
#include "prototyper.h"

#pragma config WDT = OFF
#pragma config LVP = OFF
#pragma config OSC = HS

extern volatile unsigned char OverFlow;

unsigned char Segments [] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,
							0x7D,0x07,0x7F,0x6F};   // numbers from 0-9 in for a Common Anode 7 seg 
void main (void)
{
	unsigned char count = 0;
	
	portinit ();
	TMR0_config ();
	Interrupt_Init();
	test_diode ();
	
	while (1)
	{
		if (OverFlow == 1)				// This means that my virtual flag has been raised 
		{
			LATC = Segments [count];
			count += 1; 
		
			if (count == 10)
			{
				count = 0;
			}
			OverFlow = 0;
		}
	}
}




