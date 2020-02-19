/*
 * end.c
 *
 *  Created on: Feb 13, 2020
 *      Author: ncmorgan
 */
#include "end.h"
#include <msp430.h>
#include <stdint.h>
#include<stdlib.h>
#include "peripherals.h"
#include "main.h"

void gameOver(bool uWon)
{ //true = user won
    int l = 0x00;
    int i;
    const int REPEATLENGTH = 2;
    Graphics_clearDisplay(&g_sContext); // Clear the display
    BuzzerOn(188);
    if (uWon)
    {
        //int l = 0x0F;
        int i;
//do this a number of ticks delays
        for (i = 0; i < REPEATLENGTH; i++)
        {
            setLeds(~l);
            Graphics_drawStringCentered(&g_sContext, "Congrats!",
            AUTO_STRING_LENGTH,
                                        48, 15,
                                        OPAQUE_TEXT);
            Graphics_drawStringCentered(&g_sContext, "You WON!",
            AUTO_STRING_LENGTH,
                                        48, 25,
                                        OPAQUE_TEXT);
            Graphics_flushBuffer(&g_sContext);
            swDelay(2);
        }
    }
    else if (!uWon)
    {
        for (i = 0; i < REPEATLENGTH; i++)
        {
            setLeds(~l);
            Graphics_drawStringCentered(&g_sContext, "Missed a note!",
            AUTO_STRING_LENGTH,
                                        48, 15,
                                        OPAQUE_TEXT);
            Graphics_drawStringCentered(&g_sContext, "You LOST!",
            AUTO_STRING_LENGTH,
                                        48, 25,
                                        OPAQUE_TEXT);
            Graphics_flushBuffer(&g_sContext);
            swDelay(2);
        }
    }
    setLeds(0);
    Graphics_clearDisplay(&g_sContext); // Clear the display

}

