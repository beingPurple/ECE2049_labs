/*
 * cards.h
 *
 *  Created on: Feb 12, 2020
 *      Author: ncmorgan
 */

#ifndef CARDS_H_
#define CARDS_H_

typedef struct Cards {
   char name;
   char suit;
   int val;
} card;

card makeCard(char name, int val);

#endif /* CARDS_H_ */
