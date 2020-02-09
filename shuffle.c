/*
 * shuffle.c
 *
 *  Created on: Feb 2, 2020
 *      Author: sbhatia
 */

#include "shuffle.h"
#include <string.h>
#include <msp430.h>
#include "peripherals.h"
/* char[52] cut_shuffle()
 {
 //returns an array of random cards
 char[52] base;
 char[52] shuffled;
 int[52] chosen;

 */
//cut the deck
//uses srand
void shuffle(void)
{
    char currKey = 0;
    char firstdigit;
    char cutvar[2];
    bool cutEntered = false;

    Graphics_clearDisplay(&g_sContext); // Clear the display
    Graphics_drawStringCentered(&g_sContext, "Cut the deck", AUTO_STRING_LENGTH, 48, 15, OPAQUE_TEXT);
    Graphics_flushBuffer(&g_sContext);

    while (!cutEntered)
    {
        cutvar[0] = getKey();
        cutvar[1] = getKey();
        if(cutvar[0] == '1')
        {
            if((cutvar[1] == '#') || (cutvar[1] == '*'))
            {
                cutvar[1] = ' ';
                Graphics_clearDisplay(&g_sContext); // Clear the display
                Graphics_drawStringCentered(&g_sContext, cutvar, AUTO_STRING_LENGTH, 48, 15, OPAQUE_TEXT);
                Graphics_flushBuffer(&g_sContext);
                cutEntered = true;
            }
            else if(cutvar[1] > 5)
            {
                cutvar[1] = getKey();
                Graphics_clearDisplay(&g_sContext); // Clear the display
                Graphics_drawStringCentered(&g_sContext, "Your second ", AUTO_STRING_LENGTH, 48, 15, OPAQUE_TEXT);
                Graphics_drawStringCentered(&g_sContext, "digit cannot be ", AUTO_STRING_LENGTH, 48, 25, OPAQUE_TEXT);
                Graphics_drawStringCentered(&g_sContext, "greater than 5", AUTO_STRING_LENGTH, 48, 35, OPAQUE_TEXT);
                Graphics_flushBuffer(&g_sContext);
                cutvar[1] = getKey;
            }
            else
            {
                cutvar[1] = getKey();
                Graphics_clearDisplay(&g_sContext); // Clear the display
                Graphics_drawStringCentered(&g_sContext, cutvar, AUTO_STRING_LENGTH, 48, 15, OPAQUE_TEXT);
                Graphics_flushBuffer(&g_sContext);
                cutEntered = true;
            }
        }
        else if((cutvar[1] == '#') || (cutvar[1] == '*'))
        {   
            cutvar[1] = ' ';
            Graphics_clearDisplay(&g_sContext); // Clear the display
            Graphics_drawStringCentered(&g_sContext, cutvar, AUTO_STRING_LENGTH, 48, 15, OPAQUE_TEXT);
            Graphics_flushBuffer(&g_sContext);
            cutEntered = true;
        }
        else
        {
            Graphics_clearDisplay(&g_sContext); // Clear the display
            Graphics_drawStringCentered(&g_sContext, "Input cannot be", AUTO_STRING_LENGTH, 48, 15, OPAQUE_TEXT);
            Graphics_drawStringCentered(&g_sContext, " greater than 15", AUTO_STRING_LENGTH, 48, 25, OPAQUE_TEXT);
            Graphics_drawStringCentered(&g_sContext, ". Press # or *", AUTO_STRING_LENGTH, 48, 35, OPAQUE_TEXT);
            Graphics_flushBuffer(&g_sContext);
        }
        
        /*currKey = getKey();
        if (currKey == '1')
        {   firstdigit = currKey;
            currKey = 0;
	        while (currKey == 0){
                currKey = getKey();
                if (currKey <= '5')
                {   cutvar[0] = firstdigit;
                    cutvar[1] = currKey;
                    cutvar[2] = '\0';
                    Graphics_drawStringCentered(&g_sContext, cutvar, AUTO_STRING_LENGTH, 48, 25, OPAQUE_TEXT);
                    Graphics_flushBuffer(&g_sContext);
                }

                else
                {   cutvar[0] = firstdigit;
                    Graphics_drawStringCentered(&g_sContext, cutvar, AUTO_STRING_LENGTH, 48, 25, OPAQUE_TEXT);
                }
        }

        else
        {
            System.out.println("No keypress detected")
            cutvar[0] = currKey;
            Graphics_drawStringCentered(&g_sContext, currKey, AUTO_STRING_LENGTH, 48, 25, OPAQUE_TEXT);
        } */
//srand(cutvar);
//light up leds appropriately
//say "cut: *whatever key is pressed*
    }
}
/*for(i=0;i<52)
 {        //do this 52 times
 //pick a random number b/t 0 and 51
 int rnum = rand();//the var returned from cut
 //check if this is a repeat...
 for(int n : chosen)
 {
 //is the random number in the already chosen list?
 if(chosen[n] == rnum)
 {        //pick another one

 }
 else
 {        //add to deck
 shuffled[i] = base[rnum];
 i++;
 }
 }

 }
 }

 int cut()
 {

 }
 */
