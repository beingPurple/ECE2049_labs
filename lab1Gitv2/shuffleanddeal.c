
/*
 * shuffle.c
 *
 *  Created on: Feb 2 2020
 *      Author: sbhatia
 */


#include <shuffleanddeal.h>


#define CARD_COUNT 52

int size = CARD_COUNT;


char shuffle()
{
    char deck[52][2];
    deck[0][0] = genSuit('♥');
    deck[13][0] = genSuit('S');
    deck[26][0]= genSuit('D');
    deck[39][0]= genSuit('C');

    int i;
    char sDeck[52][2];
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

    return sDeck;
}

char firstdeal(char sDeck, char hand, int cardcounter)
{
    int m;
    char h[2][2];
    char deck[52][2];
    deck[0][0] = sDeck;
    h[0][0]=hand;

    for(m=cardcounter;m<cardcounter + 2;m++)
    {
        h[m][0] = deck[m][0];
    }

    cardcounter = m;
    return h;
}

char deal(char sDeck, char hand, int cardcounter)
{
    int z = sizeof(hand)/(sizeof(char)*2);
    char h[z][2];
    char deck[52][2];
    deck[0][0] = sDeck;
    h[0][0]=hand;
    int n = cardcounter;
    h[n][0] = deck[n][0];


    cardcounter +=1;
    return h;
}

