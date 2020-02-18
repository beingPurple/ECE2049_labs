/*
 * idle.c
 *
 *  Created on: Jan 29, 2020
 *      Author: sbhatia
 */

#include "idle.h"
#include "main.h"

void idle()
{
    Graphics_clearDisplay(&g_sContext); // Clear the display
    Graphics_drawStringCentered(&g_sContext, "MSP430", AUTO_STRING_LENGTH, 48,
                                25, OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext, "Guitar Hero", AUTO_STRING_LENGTH,
                                48, 35, OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext, "Press * to start",
                                AUTO_STRING_LENGTH, 48, 45, OPAQUE_TEXT);
    Graphics_flushBuffer(&g_sContext);

    unsigned char currKey = 0;
    while (currKey != '*')
    {
        currKey = getKey();
    }
    Graphics_clearDisplay(&g_sContext); // Clear the display
    state++;
    return;
}

void replay()
{
    BuzzerOff();
    Graphics_clearDisplay(&g_sContext); // Clear the display

    Graphics_drawStringCentered(&g_sContext, "Press #",
                                AUTO_STRING_LENGTH, 48, 35, OPAQUE_TEXT);
    Graphics_drawStringCentered(&g_sContext, "to replay",
                                    AUTO_STRING_LENGTH, 48, 45, OPAQUE_TEXT);
        Graphics_flushBuffer(&g_sContext);

    unsigned char currKey = 0;
    while (currKey != '#')
    {
        currKey = getKey();
    }
    Graphics_clearDisplay(&g_sContext); // Clear the display
    state++;
    return;
}
