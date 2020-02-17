/*
 * butt.h
 *
 *  Created on: Feb 15, 2020
 *      Author: ncmorgan
 */

#ifndef BUTT_H_
#define BUTT_H_

void buttConfig();
int buttState();
char intToChar(int led);
void buzzPlay();
void configUserLED();
void lightUserLED(int led);
char buttToChar(int butt);


#endif /* BUTT_H_ */
