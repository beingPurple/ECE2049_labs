/*
 * shuffle.c
 *
 *  Created on: Feb 2, 2020
 *      Author: sbhatia
 */

#include "shuffle.h"
#include <string.h>
#include <msp430.h>
#include "peripherals.h"



void shuffle(void)
{
    char cutvar[2];
    bool digitOne = false;
    bool digitTwo = false;
    //bool cutEntered = false;

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

    while(!digitTwo)
    {
        cutvar[1] = getKey();

        if ((cutvar[0] > '1') || (cutvar[0] == '0'))
        {
            if (cutvar[1] == 0)
            {
                //Graphics_clearDisplay(&g_sContext); // Clear the display
                Graphics_drawStringCentered(&g_sContext, "Press # or *", AUTO_STRING_LENGTH, 48, 15, OPAQUE_TEXT);
                Graphics_flushBuffer(&g_sContext);
            }

            else if ((cutvar[1] != '*') && (cutvar[1] != '#'))
            {
                Graphics_clearDisplay(&g_sContext); // Clear the display
                Graphics_drawStringCentered(&g_sContext, "Input cannot be", AUTO_STRING_LENGTH, 48, 15, OPAQUE_TEXT);
                Graphics_drawStringCentered(&g_sContext, "greater than 15.", AUTO_STRING_LENGTH, 48, 25, OPAQUE_TEXT);
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

        else if(cutvar[0] == '1')
        {
            if (cutvar[1] == 0)
            {
                //Graphics_clearDisplay(&g_sContext); // Clear the display
                Graphics_drawStringCentered(&g_sContext, "Press a number", AUTO_STRING_LENGTH, 48, 15, OPAQUE_TEXT);
                Graphics_drawStringCentered(&g_sContext, "0 - 5 or # or *", AUTO_STRING_LENGTH, 48, 25, OPAQUE_TEXT);
                Graphics_flushBuffer(&g_sContext);
            }

            else if(cutvar[1] > '5')
            {
                Graphics_clearDisplay(&g_sContext); // Clear the display
                Graphics_drawStringCentered(&g_sContext, "Your second ", AUTO_STRING_LENGTH, 48, 15, OPAQUE_TEXT);
                Graphics_drawStringCentered(&g_sContext, "digit cannot be ", AUTO_STRING_LENGTH, 48, 25, OPAQUE_TEXT);
                Graphics_drawStringCentered(&g_sContext, "greater than 5", AUTO_STRING_LENGTH, 48, 35, OPAQUE_TEXT);
                Graphics_drawStringCentered(&g_sContext, "Input cannot be", AUTO_STRING_LENGTH, 48, 45, OPAQUE_TEXT);
                Graphics_drawStringCentered(&g_sContext, "greater than 15.", AUTO_STRING_LENGTH, 48, 55, OPAQUE_TEXT);
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
            Graphics_clearDisplay(&g_sContext); // Clear the display
            Graphics_drawStringCentered(&g_sContext, cutvar, AUTO_STRING_LENGTH, 48, 15, OPAQUE_TEXT);
            Graphics_flushBuffer(&g_sContext);
            digitTwo = true;
        }
    }
}
