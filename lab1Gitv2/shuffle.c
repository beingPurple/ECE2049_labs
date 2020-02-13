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
#define CARD_COUNT 52

const char* cityNames[] = {
    "Seattle",
    "Chicago",
    "San Diego",
    "Orlando",
    "Anahiem",
    "Tampa",
    "Indianapolis",
    "Portland",
    "Chelan",
    "Sandusky"
};


void shuffle()
{
    int size = CARD_COUNT;
    if (size > 1)
    {
        int i;
        //step through each index of the city name array
        for (i = 0; i < size - 1; i++)
        {
        //pick a random index (j) to swap it with
        //okay to pick same value as i
        int j = rand() % CARD_COUNT; //random between 0 and 10
        const char* temp = cityNames[j];
        cityNames[j] = cityNames[i];
        cityNames[i] = temp;
        }
    }
}
