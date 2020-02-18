/*
 * song.c
 *
 *  Created on: Feb 17, 2020
 *      Author: ncmorgan
 */
#include "main.h"
#include "song.h"

void countdown()
{
    int currtime = tc;
    while (tc - currtime < 4)
    {
        switch (tc - currtime)
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

int note2tune(char note)
{
    switch (note)
    {
    case 'A':
        return 440;
        break;
    case 'B':
        return 494;
        break;
    case 'C':
        return 523;
        break;
    case 'D':
        return 587;
        break;
    case 'E':
        return 659;
        break;
    case 'F':
        return 698;
        break;
    case 'G':
        return 784;
        break;
    }
}

void blindMice()
{
    int currtime = tc;
    int i;
    int el = tc - currtime;
    //bool lostYet;
    while (el < 4)
    {
        switch (el)
        {
        case 0:
            //play note, check for time
            BuzzerOn(note2tune('E'));

            break;
        case 1:
            BuzzerOn(note2tune('D'));
            break;
        case 2:
            BuzzerOn(note2tune('C'));
            break;
        }

    }
    uWon = true;
}

