/*
 * cards.c
 *
 *  Created on: Feb 12, 2020
 *      Author: ncmorgan
 */
#include "cards.h"
#include <stdio.h>
#include <string.h>

card makeCard( char name[2],int val)
{
    card c;

    strcpy(c.name, name[2]);
    c.val = val;
    return c;
}


