#include <p18f4520.h>
#include "prototyper.h"


volatile unsigned char OverFlow = 0;

#pragma code My_Hiprio_Int = 0x08   // high priority interrupt
void My_Hiprio_Int (void)
{
	_asm 
		GOTO chk_isr
	_endasm 
}
#pragma code 

#pragma interrupt chk_isr    // used for high priority 
void chk_isr (void)
{
	if (INTCONbits.TMR0IF == 1) // This mean that a Timer0 overflow has occured 
	{
		OverFlow = 1;			// Raise virtual flag 

		TMR0H = 0xF4;			// 1 sec delay at 3MHZ
		TMR0L = 0x8E;
		
		INTCONbits.TMR0IF = 0;	// Reset Timer0 flag
	}

}






