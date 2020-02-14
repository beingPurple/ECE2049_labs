
/*
 * shuffle.c
 *
 *  Created on: Feb 2, 2020
 *      Author: sbhatia
 */

#include "shuffle.h"
#include <string.h>
#include <msp430.h>
#include "peripherals.h"
#include "cards.h"
#include <stdio.h>

#define CARD_COUNT 52




card shuffle(card uDeck)
{
    int size = CARD_COUNT;
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
