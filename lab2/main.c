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
    configUserLED();
    state = 1;

    bool uWon = false;

    Graphics_clearDisplay(&g_sContext); // Clear the display

    //goes here if # is pressed

    while (1)
    {
        switch (state)
        {
        case 1:
            idle();
            break;
        case 2:
            lightUserLED(buttState());
            setLeds(buttState());
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

    volatile unsigned int i, j;  // volatile to prevent removal in optimization
                                 // by compiler. Functionally this is useless code

    for (j = 0; j < numLoops; j++)
    {
        i = 50000;                 // SW Delay
        while (i > 0)               // could also have used while (i)
            i--;
    }
}

