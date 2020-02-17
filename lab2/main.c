#include <msp430.h> 
#include "peripherals.h"
#include "idle.h"
#include "end.h"
#include "main.h"
#include "timer.h"
#include "butt.h"
#include  "stdbool.h"

/**
 * main.c
 */

/*
 * RUBRIC CHECKLIST
 *
 * Power Up and Reset to Welcome mode(Display welcome message) DONE
 *
 * Timer A2 properly configured with resolution set to 5 ms or less
 *
 * Count down to start of game w/ Launchpad LEDs flashing using Timer A2
 *
 * Buzzer routines with pitch and duration (min of 8 pitches)
 *
 * Playback of song at least 28 notes long using Timer A2 to measure note duration
 *
 * Playing game with timing of button (4 buttons) presses using Timer A2
 *
 * Proper player humiliation on losing DONE
 *
 * Proper celebration for winning DONE
 *
 *
 */

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

    initLeds();
    configDisplay();
    configKeypad();
    buttConfig();
    //__enable_interrupt();
    _BIS_SR(GIE);

    int preval = 0;
    bool change = false;


    bool uWon = false;

    Graphics_clearDisplay(&g_sContext); // Clear the display
    while(1){
        runtimerA2();

    if (change)
    {
        setLeds(buttState());
        buzzPlay();
        swDelay(2);
        change = false;
    }
    preval = buttState();
    }

//do nothing routine
    ///if bottonpress is different from what it was last time, sound an interupt which sets something to true
    //the thing in the true loop happens, turns itself off, and back to idle

//    while (1)
//    {
//        setLeds(buttState());
//        buzzPlay();
//        swDelay(2);
////        Graphics_drawStringCentered(&g_sContext, intToChar(buttState()), AUTO_STRING_LENGTH, 48, 15, TRANSPARENT_TEXT);
////        Graphics_flushBuffer(&g_sContext);
//        // setLeds(0);
//    }

    //celebrate or humiliate
    //gameOver(uWon);
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

    volatile unsigned int i, j;  // volatile to prevent removal in optimization
                                 // by compiler. Functionally this is useless code

    for (j = 0; j < numLoops; j++)
    {
        i = 50000;                 // SW Delay
        while (i > 0)               // could also have used while (i)
            i--;
    }
}

