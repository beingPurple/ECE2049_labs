/************** ECE2049 DEMO CODE ******************/
/**************  13 March 2019   ******************/
/***************************************************/


#include "main.h"
#include <msp430.h>
#include "peripherals.h"

// Declare globals here
int state = 0; //state tracker
int seed; //random shuffle + deal seed
bool held = false; //tracks if player has held or not
bool cheld = false;
bool uWon = true; //default is userwins
char uhand[11][2];
char chand[11][2];
int cardcounter = 0;
char sDeck[52][2];
char set[13][2];//13 rows, 2 columns
// Main
void main(void)

{
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer. Always need to stop this!!
                              // You can then configure it properly, if desired
    initLeds();
    configDisplay();
    configKeypad();

    while (1)
    {

        switch (state)
        {
        case 0: //idle case
            idle(); //idle func(pretty lights, wait for player to enter a number)
            Graphics_drawStringCentered(&g_sContext, "after idle", AUTO_STRING_LENGTH, 48, 15, OPAQUE_TEXT);
            Graphics_flushBuffer(&g_sContext);
            state++;
            break;
        case 1:

            swDelay(3);
            seed = keypress();
            srand(seed);
            char seed = seed;
            Graphics_clearDisplay(&g_sContext); // Clear the display
            Graphics_drawStringCentered(&g_sContext, seed , AUTO_STRING_LENGTH, 48, 15, OPAQUE_TEXT);
            Graphics_flushBuffer(&g_sContext);

            //shuffle and deal, etc.
            //cut func
            //shuffle and deal func
            //bet func (changes s)
            state++;
            break;
        case 2: //player's turn
            if (!held)
            {
                //if holdOrDraw bool (implements player's choice of holding or drawing where 1 = hold
                //draw func
                held = userPlay(held);
                //function to check if won, takes in current hand
                state = 3;
            }
            //set states based on checked conditions. Check if bust, held, etc.

            //check for user bust
            if (bustCheck(uhand))                //if player busted
            {
                uWon = false;                //user lost
                state = 4;
            }
            if (cheld && held == true) //standoff for if both hold before busting. true is player looses
            {

                if (standoff(uhand, chand) == true) //TODO implement user hand and player hand. They are 2d arrays.
                {
                    uWon = false;
                    state = 4;
                }

            }

            state++;

            break;
        case 3: //comp's turn
            //computer decision func
            if (!cheld)
            {
                cheld = cPlay(cheld);
                //function to check if won, takes in current hand
                state = 2;
            }

            // check for computer bust
            if (bustCheck(chand))
            {
                state = 4;
            }

            if (cheld && held == true) //standoff for if both hold before busting. true is player looses
            {

                if (standoff(uhand, chand) == true) //TODO implement user hand and player hand. They are 2d arrays.
                {
                    uWon = false;
                    state = 4;
                }

            }

            break;
        case 4: //end game
            gameOver(uWon);
            state = 0;
            break;

        }
    }

}

void swDelay(char numLoops)
{
    // This function is a software delay. It performs
    // useless loops to waste a bit of time
    //
    // Input: numLoops = number of delay loops to execute
    // Output: none
    //
    // smj, ECE2049, 25 Aug 2013

    volatile unsigned int i, j;	// volatile to prevent removal in optimization
                                // by compiler. Functionally this is useless code

    for (j = 0; j < numLoops; j++)
    {
        i = 50000;					// SW Delay
        while (i > 0)				// could also have used while (i)
            i--;
    }
}
