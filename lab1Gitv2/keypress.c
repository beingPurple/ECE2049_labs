/*
 * shuffle.c
 *
 *  Created on: Feb 2, 2020
 *      Author: sbhatia
 */

#include <keypress.h>
#include <string.h>
#include <msp430.h>
#include "peripherals.h"



int keypress(void)
{
    char cutvar[2];
    bool digitOne = false;
    bool digitTwo = false;
    int c;


    Graphics_clearDisplay(&g_sContext); // Clear the display
    Graphics_drawStringCentered(&g_sContext, "Cut the deck", AUTO_STRING_LENGTH, 48, 15, OPAQUE_TEXT);
    Graphics_flushBuffer(&g_sContext);

    while(!digitOne)
    {
        cutvar[0] = getKey();

        if((cutvar[0] == '*') || (cutvar[0] == '#') || (cutvar[0] == 0))
        {
            Graphics_drawStringCentered(&g_sContext, "Insert 1st Digit", AUTO_STRING_LENGTH, 48, 15, OPAQUE_TEXT);
            Graphics_flushBuffer(&g_sContext);
        }

        else
        {
            Graphics_drawStringCentered(&g_sContext, "Insert 2nd Digit", AUTO_STRING_LENGTH, 48, 15, OPAQUE_TEXT);
            Graphics_flushBuffer(&g_sContext);
            digitOne = true;
        }
    }

    Graphics_clearDisplay(&g_sContext); // Clear the display

    while(!digitTwo)
    {
        cutvar[1] = getKey();

        if(cutvar[0] == '1')
        {
            if ((cutvar[1] == 0) || (cutvar[1] > '5'))
            {
                Graphics_drawStringCentered(&g_sContext, "Press a number", AUTO_STRING_LENGTH, 48, 15, OPAQUE_TEXT);
                Graphics_drawStringCentered(&g_sContext, "0 - 5 or # or *", AUTO_STRING_LENGTH, 48, 25, OPAQUE_TEXT);
                Graphics_flushBuffer(&g_sContext);
            }

            else if((cutvar[1] != '#') || (cutvar[1] != '*'))
            {
                Graphics_clearDisplay(&g_sContext); // Clear the display
                Graphics_drawStringCentered(&g_sContext, cutvar, AUTO_STRING_LENGTH, 48, 15, OPAQUE_TEXT);
                Graphics_flushBuffer(&g_sContext);
                digitTwo = true;
            }

            else
            {
                Graphics_clearDisplay(&g_sContext); // Clear the display
                Graphics_drawStringCentered(&g_sContext, cutvar, AUTO_STRING_LENGTH, 48, 15, OPAQUE_TEXT);
                Graphics_flushBuffer(&g_sContext);
                digitTwo = true;
            }
        }
        else
        {
            if ((cutvar[1] == 0) || ((cutvar[1] != '*') && (cutvar[1] != '#')))
            {
                Graphics_drawStringCentered(&g_sContext, "Press # or *", AUTO_STRING_LENGTH, 48, 15, OPAQUE_TEXT);
                Graphics_flushBuffer(&g_sContext);
            }

            else
            {
                Graphics_clearDisplay(&g_sContext); // Clear the display
                Graphics_drawStringCentered(&g_sContext, cutvar, AUTO_STRING_LENGTH, 48, 15, OPAQUE_TEXT);
                Graphics_flushBuffer(&g_sContext);
                digitTwo = true;
            }
        }
    }

    c = atoi(cutvar);
    return c;
}
