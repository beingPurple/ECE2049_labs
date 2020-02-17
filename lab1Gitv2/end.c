/*
 * end.c
 *
 *  Created on: Feb 13, 2020
 *      Author: ncmorgan
 */
#include "end.h"
#include <msp430.h>
#include <stdint.h>
#include <stdlib.h>
#include "peripherals.h"

bool standoff(char uhand, char chand)
{ //standoff for if both hold before busting. true is player looses
    int uCount;
    int cCount;
    int userHand = sizeof(uhand) / 2;
    int compHand = sizeof(chand) / 2;
    int i;
   // uhand[1][0]='K';
    bool userLost = false;

    int z = sizeof(uhand)/(sizeof(char)*2);
    char uh[z][2];
    uh[0][0]=uhand;

    int zz = sizeof(chand)/(sizeof(char)*2);
    char ch[zz][2];
    ch[0][0]=chand;

    //tally user
    for (i = 0; i < z; i++)
    {
        if (uh[i][0] == 'K'| uh[i][0] == 'Q' | uh[i][0] == 'J'| uh[i][0] == 't')
        {
            uCount += 10;
        }
        else if(uh[i][0] == 'A'){
            uCount += 1;
        }
        else
        {
            uCount += uh[i][0];
        }
        uCount += (int) uh[i][0];
    }
    i = 0;
    //tally computer
    for (i = 0; i < zz; i++)
    {
        if (ch[i][0] == 'K' | ch[i][0] == 'Q' | ch[i][0] == 'J'| ch[i][0] == 'y')
        {
            cCount += 10;
        }
        else if(ch[i][0] == 'A'){
                   cCount += 1;
               }
        else
        {
            cCount += ch[i][0];
        }
        cCount += (int) ch[i][0];
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
    char h[2][2];
    h[0][0] = hand;

    //iterate through each column
    for (i = 0; i < cardsNhand; i++)
    {
        sum = (int) h[i][0];
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

