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

bool standoff(char uhand, char chand)
{ //standoff for if both hold before busting. true is player looses
    int uCount;
    int cCount;
    int userHand = sizeof(uhand) / 2;
    int compHand = sizeof(chand) / 2;
    int i;
    uhand[1][0]='K';
    bool userLost = false;
    //tally user
    for (i = 0; i < userHand; i++)
    {
        if (uhand[i][0] == 'K'| uhand[i][0] == 'Q' | uhand[i][0] == 'J')
        {
            uCount += 10;
        }
        else
        {

        }
        uCount += (int) uhand[i][0];
    }
    i = 0;
    //tally computer
    for (i = 0; i < compHand; i++)
    {
        if (chand[i][0] == 'K' | chand[i][0] == 'Q' | chand[i][0] == 'J')
        {
            cCount += 10;
        }
        else
        {

        }
        uCount += (int) uhand[i][0];
    }
    if (uCount > cCount)
    {
        userLost = false;

    }
    else if (cCount > uCount)
    {
        userLost = true;
    }
    return userLost;
}
bool bustCheck(char hand)
{ //also a 2d array of the respective player's hand
    bool busted = false;
    int cardsNhand = sizeof(hand) / 2;
    int sum = 0;
    int i;

    //iterate through each column
    for (i = 0; i < cardsNhand; i++)
    {
        sum = (int) hand[i][0];
    }
    if (sum > 20)
    {
        busted = true;
    }

    return busted;
}
void gameOver(bool uWon)
{ //true = user won
    int l = 0x15;
    int i;
    const int REPEATLENGTH = 20;
    Graphics_clearDisplay(&g_sContext); // Clear the display
    BuzzerOn();
    if (uWon)
    {
        int l = 0x15;
        int i;
//do this a number of ticks delays
        for (i = 0; i < REPEATLENGTH; i++)
        {
            setleds(~l);
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
            setleds(~l);
            Graphics_drawStringCentered(&g_sContext, "Sucks to suck!",
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
}

