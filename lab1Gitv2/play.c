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

bool userPlay(bool held)
{
    while (!held)
    {
        //hold or draw?
        Graphics_drawStringCentered(&g_sContext, "'*' to hold",
        AUTO_STRING_LENGTH,
                                    48, 15, OPAQUE_TEXT);
        Graphics_drawStringCentered(&g_sContext, "'#' to draw",
        AUTO_STRING_LENGTH,
                                    48, 25, OPAQUE_TEXT);
        Graphics_flushBuffer(&g_sContext);

        char k = keyGetter();
        if (k == '*')
        { //hold
            Graphics_clearDisplay(&g_sContext); // Clear the display
            Graphics_drawStringCentered(&g_sContext, "holding!",
            AUTO_STRING_LENGTH,
                                        48, 15, OPAQUE_TEXT);
            Graphics_flushBuffer(&g_sContext);
            held = true;
        }
        else if (k == '#')
        { //draw
            Graphics_clearDisplay(&g_sContext); // Clear the display
            Graphics_drawStringCentered(&g_sContext, "drawing!",
            AUTO_STRING_LENGTH,
                                        48, 15, OPAQUE_TEXT);
            Graphics_flushBuffer(&g_sContext);
            //Deal function, as per shruti
            //calculate if bust
        }
        else
        { //invalid entry

            Graphics_drawStringCentered(&g_sContext, "invalid entry!",
            AUTO_STRING_LENGTH,
                                        48, 35, OPAQUE_TEXT);
            Graphics_flushBuffer(&g_sContext);
            Graphics_drawStringCentered(&g_sContext, "choose again!",
            AUTO_STRING_LENGTH,
                                        48, 45, OPAQUE_TEXT);
            Graphics_flushBuffer(&g_sContext);
            held = userPlay(held); //not 100% sure on how this will wind up. first iteration at it.
        }

    }
    return held;
}

bool cPlay(bool held) //will probably need to insert an array of cards
{
    Graphics_clearDisplay(&g_sContext); // Clear the display
    Graphics_drawStringCentered(&g_sContext, "computer's turn!",
    AUTO_STRING_LENGTH,
                                48, 15, OPAQUE_TEXT);
    Graphics_flushBuffer(&g_sContext);

    //decide if hold or draw
    //holds above 17 cards in hand
    while (!held)
    {
        if (1)
        {        //TODO: If the omputer's hand is less than or equal to 17
            Graphics_drawStringCentered(&g_sContext, "drawing!",
            AUTO_STRING_LENGTH,
                                        48, 25, OPAQUE_TEXT);
            Graphics_flushBuffer(&g_sContext);
            //TODO: draw a card
            held = false;
        }
        else
        {        //18 and up, change held to true
            Graphics_drawStringCentered(&g_sContext, "I'll hold",
            AUTO_STRING_LENGTH,
                                        48, 25, OPAQUE_TEXT);
            Graphics_flushBuffer(&g_sContext);
            held = true;
        }
    }

    return held;

}

