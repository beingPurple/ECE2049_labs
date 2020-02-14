/*
 * cards.h
 *
 *  Created on: Feb 12, 2020
 *      Author: ncmorgan
 */

#ifndef CARDS_H_
#define CARDS_H_
#include <stdio.h>
#include <string.h>
#include <msp430.h>
#include <stdlib.h>

typedef struct Cards {
   char name;
   char suit;
   int val;
   char card[52];
} card;

card makeCard(char name, int val);

#endif /* CARDS_H_ */
