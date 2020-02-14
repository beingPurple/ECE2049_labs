/*
 * end.h
 *
 *  Created on: Feb 13, 2020
 *      Author: ncmorgan
 */

#ifndef END_H_
#define END_H_
#include <msp430.h>
#include<stdlib.h>
#include "peripherals.h"

bool standoff(char uhand,char chand);
void gameOver(bool uWon);
bool bustCheck(char hand);
#endif /* END_H_ */
