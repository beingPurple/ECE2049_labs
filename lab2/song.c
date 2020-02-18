/*
 * song.c
 *
 *  Created on: Feb 17, 2020
 *      Author: ncmorgan
 */
#include "main.h"

void countdown()
{
    int currtime = tc;
    while (tc-currtime < 4)
    {
        switch (tc-currtime)
        {
        case 1:
            Graphics_drawStringCentered(&g_sContext, "3...",
            AUTO_STRING_LENGTH,
                                        48, 45, OPAQUE_TEXT);
            Graphics_flushBuffer(&g_sContext);
            break;
        case 2:
            Graphics_drawStringCentered(&g_sContext, "2...",
            AUTO_STRING_LENGTH,
                                        48, 45, OPAQUE_TEXT);
            Graphics_flushBuffer(&g_sContext);
            break;
        case 3:
            Graphics_drawStringCentered(&g_sContext, "1...",
            AUTO_STRING_LENGTH,
                                        48, 45, OPAQUE_TEXT);
            Graphics_flushBuffer(&g_sContext);
            break;
        }

    }
    Graphics_clearDisplay(&g_sContext); // Clear the display

}

void blindMice(){

}

