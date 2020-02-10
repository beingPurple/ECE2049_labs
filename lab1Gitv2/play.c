/*
 * play.c
 *
 *  Created on: Feb 9, 2020
 *      Author: ncmorgan
 */
#include <msp430.h>
#include <stdint.h>
#include "grlib/grlib.h"
#include "peripherals.h"

void userPlay(bool held)
{
    while (!held)
    {
        //hold or draw?
        Graphics_drawStringCentered(&g_sContext, "'*' to hold",
                                    AUTO_STRING_LENGTH, 48, 15, OPAQUE_TEXT);
        Graphics_drawStringCentered(&g_sContext, "'#' to draw",
                                    AUTO_STRING_LENGTH, 48, 15, OPAQUE_TEXT);
        Graphics_flushBuffer(&g_sContext);
        char currKey = 0;
        while(currKey == 0){
            currKey = 0;
        }
    }
}

void cPlay()
{

}

