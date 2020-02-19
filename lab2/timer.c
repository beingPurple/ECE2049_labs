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

// Timer A2 interrupt service routine
#pragma vector=TIMER2_A0_VECTOR
__interrupt void TimerA2_ISR(void)
{
    if (tdir)
    {
        timer_cnt++;
        if (timer_cnt == 120000)
            timer_cnt = 0;
        if (timer_cnt % 100 == 0) // blink LEDs once a second
        {
            P1OUT = P1OUT ^ BIT0;
            P4OUT ^= BIT7;
            tc++;
        }
    }
    else
        timer_cnt--;
}
