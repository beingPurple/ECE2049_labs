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
card genDeck()
{
    card newDeck[52];

    newDeck[0] = makeCard("A♥", 1);
    newDeck[1] = makeCard("2♥", 2);
    newDeck[2] = makeCard("3♥", 3);
    newDeck[3] = makeCard("4♥", 4);

    return newDeck[52];
}

card genh(char suit)
{
    int i;
    std::string;
    for (i = 0; i < 13; i++)
    {
        if (i == 0)
        {
            in =
            {   "A", suit};
            makeCard(in, i + 1);
        }
        else if (i < 0 && i < 10)
        {
        makeCard(
                {   (i + 1) , suit}, i + 1);
    }
    else
    {
        if (i == 10)
        {
        makeCard(
                {   "K" , suit}, 10);
    }
    else if (i == 11)
    {
    makeCard(
            {   "Q" , suit}, 10);
}
else if (i == 12)
{
makeCard(
        {   "J" , suit}, 10);
}
}
}
}

