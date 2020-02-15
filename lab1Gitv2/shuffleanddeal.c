
/*
 * shuffle.c
 *
 *  Created on: Feb 2 2020
 *      Author: sbhatia
 */


#include "shuffleanddeal.h"
#define CARD_COUNT 52

void shuffle(char sDeck[52][2], char set[13][2])
{
    int size = CARD_COUNT;
    char deck[52][2];
    deck[0][0] = genSuit('♥',set[13][2]);
    deck[13][0] = genSuit('S',set[13][2]);
    deck[26][0]= genSuit('D',set[13][2]);
    deck[39][0]= genSuit('C',set[13][2]);

    int i;
    //char sDeck[52][2];
    int j = rand() % CARD_COUNT;
    int k;

    for(k=0;k<52;k++)
    {
        sDeck[k][0] = '0';
        sDeck[k][1] = '0';
    }
        //step through each index of the city name array
        for (i = 0; i < size - 1; i++)
        {
            while (sDeck[j][0] != 0)
            {
               int j = rand() % CARD_COUNT;
            }
            sDeck[j][0] = deck[i][0];

        }
}

void firstdeal(char sDeck[52][2], char hand[11][2], int cardcounter)
{
    int m;

    for(m=cardcounter;m<cardcounter + 2;m++)
    {
        hand[m][0] = sDeck[m][0];
    }

    cardcounter = m;
}

void deal(char sDeck[52][2], char hand[11][2], int cardcounter)
{
    int n = cardcounter;

    hand[n][0] = sDeck[n][0];
    cardcounter +=1;
}

