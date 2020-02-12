/*
 * cards.h
 *
 *  Created on: Feb 12, 2020
 *      Author: ncmorgan
 */

#ifndef CARDS_H_
#define CARDS_H_

typedef struct Cards {
   char name[2];
   int val;
} card;

card makeCard( char name[2],int val);


#endif /* CARDS_H_ */
