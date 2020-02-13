/*
 * cards.c
 *
 *  Created on: Feb 12, 2020
 *      Author: ncmorgan
 */
#include "cards.h"
#include <stdio.h>
#include <string.h>

<<<<<<< HEAD
card makeCard(char name[2], int val)
=======
card makeCard(char name[2],int val)
>>>>>>> f93ed7be85d500fbfed4228a60deb7b0c81593d6
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

