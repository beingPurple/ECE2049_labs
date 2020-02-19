/*
 * main.h
 *
 *  Created on: Feb 15, 2020
 *      Author: ncmorgan
 */

#ifndef MAIN_H_
#define MAIN_H_
#include <msp430.h>
#include "peripherals.h"
#include "idle.h"
#include "end.h"
#include "main.h"
#include "timer.h"
#include "butt.h"
#include  "stdbool.h"
#include "song.h"



bool uWon;
void swDelay(char numLoops);
int preval;
bool change;
int state;
long unsigned int timer_cnt;
char tdir;
int tc;
int missed;
char currKey;
bool m;
#endif /* MAIN_H_ */
