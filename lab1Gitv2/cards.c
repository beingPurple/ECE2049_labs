/*
 * cards.c
 *
 *  Created on: Feb 12, 2020
 *      Author: ncmorgan
 */
#include "cards.h"


card makeCard(char name, int val)

{
    card v;
    v.name = name;
    v.val = val;

    return v;

}

card genSuit(char suit)
{
    int i;
    card c;
    for (i = 0; i < 13; i++)
    {
        char in[2];
        in[1] = suit;
        if (i == 0)
        {
            in[0] = 'A';
            makeCard(in, 11);
        }
        else if (i < 0 && i < 10)
        {
            in[0] = i + 1;
            makeCard(in, i + 1);
        }
        else
        {
            if (i == 10)
            {
                in[0] = 'K';
                makeCard(in, 10);
            }
            else if (i == 11)
            {
                in[0] = 'Q';
                makeCard(in, 10);
            }
            else if (i == 12)
            {
                in[0] = 'J';
                makeCard(in, 10);
            }
        }
    }
    return c;
}

