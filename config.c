#include <p18f4520.h>
#include "prototyper.h"

void portinit (void)
{
	TRISDbits.TRISD3 = 0;			// Pin used to check if there is power on ckt 
	LATDbits.LATD3   = 0;			// Initialize to zero 

	TRISC = 0x00;					// Seven Segment 
	LATC  = 0x00;					// Initialize to zero
}

void TMR0_config (void)
{
	INTCONbits.TMR0IF = 0;
	T0CON = 0x07;    // use a p.s of 1:256 @ internal clock 

	TMR0H = 0xF4;			// 1 sec delay at 3MHZ
	TMR0L = 0x8E;

	T0CONbits.TMR0ON = 1;	// Enable Timer0
}

void Interrupt_Init (void)
{
	INTCONbits.PEIE = 1;
	INTCONbits.GIE = 1;
	INTCONbits.TMR0IE = 1;		
}
