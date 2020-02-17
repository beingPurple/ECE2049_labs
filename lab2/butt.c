/*
 * q2q3.c
 *
 *  Created on: Feb 5, 2020
 *      Author: Noelle
 */

/*
 * 2)  Write  a  function  to  configure  the  4  lab  board  buttons,
 * S1  through  S4  See  the  Lab  Board schematics, Homework 2 and Lectures
 * 6-8 for information on digital IO and the buttons.
 */
#include "msp430.h"
#include "peripherals.h"
#include <stdlib.h>

void buttConfig()
{
    //buttons: p7.0, p3.6, p2.2, p7.4, must be tied up

    //select for io (0 is io) and direction (0 IS INPUT)
    P7SEL &= ~(BIT0 | BIT4);
    P7DIR &= ~(BIT0 | BIT4);
    P3SEL &= ~(BIT6);
    P3DIR &= ~(BIT6);
    P2SEL &= ~(BIT2);
    P2DIR &= ~(BIT2);

    //pull it all up (1 is pullup)
    P7REN |= (BIT0 | BIT4);
    P3REN |= (BIT6);
    P2REN |= (BIT2);
}

/*3)  Write  a  function  that  returns  the  state  of  the  lab
 * board  buttons  with  1=pressed  and  0=not pressed. For example if
 * S1 alone is pressed then the function should return 00000001b = 0x01.
 * If only S3 is pressed then the function should return 00000100b = 0x04.
 * If both S1 and S3 are pressed then  the  function  should  return
 * 00000101b  =  0x05,  etc.  Remember  that  the  buttons  are  not  on
 * contiguous I/O port pins. You will have to check button each individually
 * and combine their states before returning from your function.
 */

char intToChar(int led)
{
    char setter;
    setter = 0x0;
    if (led == 4)
    {
        setter = 0x8;
    }
    else if (led == 3)
    {
        setter = 0x4;
    }
    else if (led == 2)
    {
        setter = 0x2;
    }
    else if (led == 1)
    {
        setter = 0x1;
    }
    return setter;
}
int buttState()
{
    //remember, we are looking for ZEROES as pressed buttons!
    int state = 0x00; //fill with ones
    //setLeds(0);

    if (~P7IN & (BIT4))
    {
        state |= BIT0;
    }
    if (~P3IN & BIT6)
    {
        state |= BIT2;
    }
    if (~P2IN & BIT2)
    {
        state |= BIT1;
    }
    if (~P7IN & BIT0)
    {

        state |= BIT3;
    }
    return state;
}

void buzzPlay(){
    int buzzNum = buttState();
    if(buzzNum == 0){
        BuzzerOff();
    }
    else{
        BuzzerOn(buzzNum);
    }
}

