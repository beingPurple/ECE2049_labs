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


char shuffle(char uDeck);
char firstdeal(card sDeck, bool held);



#endif /* SHUFFLEANDDEAL_H_ */
