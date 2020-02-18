/*
 * timer.c
 *
 *  Created on: Feb 15, 2020
 *      Author: ncmorgan
 */
#include <msp430.h>
#include "main.h"
#include "butt.h"
// timer_cnt=0;
// tdir = 1;

void runtimerA2(void)
{
// This function configures and starts Timer A2
// Timer is counting ~0.01 seconds
//
// Input: none, Output: none
//
// smj, ECE2049, 17 Sep 2013
//
// Use ACLK, 16 Bit, up mode, 1 divider
    TA2CTL = TASSEL_1 + MC_1 + ID_0;
    TA2CCR0 = 327; // 327+1 = 328 ACLK tics = ~1/100 seconds
    TA2CCTL0 = CCIE; // TA2CCR0 interrupt enabled
}

void displayTime(unsigned int inTme)
{
// This converts the global counter variable timer_cnt to a display
// of minutes and seconds -- MM:SS.S
//
// Input: none, Output: none
//
// smj, ECE2049, 17 Sep 2013
char asc_arr[6];
unsigned int min;
unsigned int sec;
unsigned int msec;
//. . .
/* Calling the draw command with OPAQUE_TEXT instead of TRANSPARENT_TEXT
removes the need to clear whole screen with every update */
 Graphics_drawStringCentered(&g_sContext, asc_arr,6,51,32,OPAQUE_TEXT);
 Graphics_flushBuffer(&g_sContext);
 // . . .
}

// Timer A2 interrupt service routine
#pragma vector=TIMER2_A0_VECTOR
__interrupt void TimerA2_ISR(void)
{
    if (tdir)
    {
        timer_cnt++;
        if (timer_cnt == 60000)
            timer_cnt = 0;
        if (timer_cnt % 50 == 0) // blink LEDs once a second
        {
            P1OUT = P1OUT ^ BIT0;
            P4OUT ^= BIT7;
            tc++;
        }
    }
    else
        timer_cnt--;
}
