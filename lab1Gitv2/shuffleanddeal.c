
/*
 * shuffle.c
 *
 *  Created on: Feb 2 2020
 *      Author: sbhatia
 */


#include <shuffleanddeal.h>


#define CARD_COUNT 52

int size = CARD_COUNT;
char uDeck[109] = {"HA", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "HJ", "HQ", "HK", "DA", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10",
    "DJ", "DQ", "DK", "CA", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "CJ", "CQ", "CK", "SA", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",
    "S10", "SJ", "SQ", "SK"};

char shuffle(char uDeck)
{

    int i;

    const char* sDeck[52] = {0};
    int j = rand() % CARD_COUNT;

        //step through each index of the city name array
        for (i = 0; i < size - 1; i++)
        {
            if (sDeck[j] != 0)
            {
               int j = rand() % CARD_COUNT;
            }

            sDeck[j] = uDeck[i];
        }

    return sDeck;
}

char firstdeal(card sDeck bool held)
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
        }

    return sDeck[52];
}

/* while !firstdeal
 * increment card count by 1
 *
 * for card count in sDeck
 *
 * card1 = sDeck.name[card count]
 */
