/*
 * shuffle.h
 *
 *  Created on: Feb 2, 2020
 *      Author: sbhatia
 */

#ifndef SHUFFLEANDDEAL_H_
#define SHUFFLEANDDEAL_H_
#include "cards.h"
#include "peripherals.h"
#include <stdio.h>
#include <string.h>
#include <msp430.h>


void shuffle(char sDeck[52][2], char set [13][2]);
void firstdeal(char sDeck[52][2], char hand[11][2], int cardcounter);
void deal(char sDeck[52][2], char hand[11][2], int cardcounter);



#endif /* SHUFFLEANDDEAL_H_ */
