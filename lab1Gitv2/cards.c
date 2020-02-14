/*
 * cards.c
 *
 *  Created on: Feb 12, 2020
 *      Author: ncmorgan
 */
#include "cards.h"


//card makeCard(char name, int val, char card)
//
//{
//    card v;
//    v.name = name;
//    v.val = val;
//    v.card = card;
//
//    return v;
//
//}

//makeCard(H2,2,)

char genSuit(char suit)
{
    int i;
    char set[13][2];//13 rows, 2 columns
    //card c;
    for (i = 0; i < 13; i++)
    {
        char in[2];
        in[1] = suit;
        if (i == 0)
        {
            in[0] = 'A';

        }
        else if (i > 0 && i < 9)
        {
            in[0] = i + 1;
        }
        else if (i == 9)
        {
            in[0] = 't';
        }
        else
        {
            if (i == 10)
            {
                in[0] = 'K';
            }
            else if (i == 11)
            {
                in[0] = 'Q';
            }
            else if (i == 12)
            {
                in[0] = 'J';
            }
        }
        set[i][0] = in[0];
    }
    return set;
}

