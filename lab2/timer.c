/*
 * timer.c
 *
 *  Created on: Feb 15, 2020
 *      Author: ncmorgan
 */
#include <msp430.h>
#include "main.h"

long unsigned int timer_cnt=0;//this should be global. Might be good to ask TA where this line should go

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

void stoptimerA2(int reset)
{
// This function stops Timer A2 andresets the global time variable
// if input reset = 1
//
// Input: reset, Output: none
//
// smj, ECE2049, 17 Sep 2013
//
    TA2CTL = MC_0; // stop timer
    TA2CCTL0 &= ~CCIE; // TA2CCR0 interrupt disabled
    if (reset)
        timer_cnt = 0;
}
