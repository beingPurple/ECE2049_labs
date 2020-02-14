
/*
 * shuffle.c
 *
 *  Created on: Feb 2, 2020
 *      Author: sbhatia
 */


#include <shuffleanddeal.h>


#define CARD_COUNT 52

int size = CARD_COUNT;


card shuffle(card uDeck)
{

    int i;
    int j = rand() % CARD_COUNT;
    card sDeck[52] = {0};

        //step through each index of the city name array
        for (i = 0; i < size - 1; i++)
        {
            sDeck[j] = uDeck[i];
            while (sDeck[j] != 0)
            {
                int j = rand() % CARD_COUNT;

            }
        }

    return sDeck;
}

char firstdeal(card sDeck, bool held)
{
    int k;
    char card1[2];
    char card2[2];

/* while first deal
 *      increment card count by 2
 *    for card count in sDeck
 *      card1 = sDeck.name[card count]
 *      card2 = sDeck.name[card count + 1]
 */


}

/* while !firstdeal
 * increment card count by 1
 *
 * for card count in sDeck
 *
 * card1 = sDeck.name[card count]
 */
