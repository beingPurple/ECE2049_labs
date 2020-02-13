/*
 * cards.c
 *
 *  Created on: Feb 12, 2020
 *      Author: ncmorgan
 */
#include "cards.h"
#include <stdio.h>
#include <string.h>

card makeCard(char name[2],int val)
{
    card v;
    strcpy(v.name, name[2]);
    v.val = val;

    return v;



}
 card genDeck(){
    card newDeck[52];

    newDeck[0] = makeCard("A♥",1);
    newDeck[1] = makeCard("2♥",2);
    return newDeck[52];
}

