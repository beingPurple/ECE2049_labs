/************** ECE2049 DEMO CODE ******************/
/**************  13 March 2019   ******************/
/***************************************************/

#include <msp430.h>

/* Peripherals.c and .h are where the functions that implement
 * the LEDs and keypad, etc are. It is often useful to organize
 * your code by putting like functions together in files.
 * You include the header associated with that file(s)
 * into the main file of your project. */
#include "peripherals.h"
#include "idle.h"
#include "play.h"
#include "cards.h"
#include "keypress.h"
#include "shuffle.h"
#include "end.h"

// Function Prototypes
void swDelay(char numLoops);

// Declare globals here
int state = 0; //state tracker
int seed; //random shuffle + deal seed
card uDeck[52];
bool held = false; //tracks if player has held or not
bool cheld = false;


// Main
void main(void)

{
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer. Always need to stop this!!
                              // You can then configure it properly, if desired
    initLeds();
    configDisplay();
    configKeypad();

    Graphics_clearDisplay(&g_sContext); // Clear the display
    Graphics_drawStringCentered(&g_sContext, "before switch",
                                AUTO_STRING_LENGTH, 48, 15, TRANSPARENT_TEXT);
    Graphics_flushBuffer(&g_sContext);

    while (1)
    {
        card sDeck;
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
            sDeck = shuffle(uDeck); //shuffle the real deck by passing in realDeck and reassigning its values
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
            state++;

            break;
        case 3: //comp's turn
            //computer decision func
            if(!cheld){
                cheld = cPlay(cheld);
                //function to check if won, takes in current hand
                state = 2;
            }
            if(cheld && held == true){
                state = 4;//specify which state to go go, not +=2
            }
           // state--;//needs to be an if statement too

            break;
        case 4: //end game
            //end game func (display results, patronize or praise player)
            //check and display on the LEDs, and then the buzzer. Use demo code functions. setleds(0x15) lights all 4 leds. toggle to make it blink.

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
