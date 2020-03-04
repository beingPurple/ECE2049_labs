#include <msp430.h> 
#include "peripherals.h"
#include "idle.h"
#include "end.h"
#include "main.h"
#include "timer.h"
#include "butt.h"
#include  "stdbool.h"
#include "song.h"

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
    runtimerA2();

    state = 1;
    tc = 0;
    bool m;

    bool uWon = false;
    //__enable_interrupt();
    _BIS_SR(GIE);
    timer_cnt = 0;
    tdir = 1;

    Graphics_clearDisplay(&g_sContext); // Clear the display

    //goes here if # is pressed
    unsigned char currKey = 0;
    while (1)
    {
        switch (state)
        {
        case 1:
            idle();
            state = 6;
            break;
        case 2: //a debug state, mostly
            lightUserLED(buttState());
            setLeds(buttState());
            if (buttState() == 0x01)
            {
                BuzzerOn(440);
            }
            else
            {
                BuzzerOff();

            }
            // runtimerA2();
            break;
        case 3:

        case 4:
            gameOver(uWon);
            state = 5;
            break;
        case 5:
            replay();
            uWon = false;
            currKey = 0;
            state = 6;
            break;
        case 6:

            m = false;
            currKey = 0;
            bool done;
            done = false;
            missed = 0;
            countdown();
            while (currKey != '#' && missed < 4 && done != true)
            {
                writeSong(50, 'E');
                if (m == true)
                {
                    missed++;
                    m = false;
                }
                writeSong(50, 'D');
                if (m == true)
                {
                    missed++;
                    m = false;
                }
                writeSong(100, 'C');
                if (m == true)
                {
                    missed++;
                    m = false;
                }
                writeSong(50, 'E');
                if (m == true)
                {
                    missed++;
                    m = false;
                }
                writeSong(50, 'D');
                if (m == true)
                {
                    missed++;
                    m = false;
                }
                writeSong(100, 'C');
                if (m == true)
                {
                    missed++;
                    m = false;
                }
                writeSong(50, 'F');
                if (m == true)
                {
                    missed++;
                    m = false;
                }
                writeSong(50, 'E');
                if (m == true)
                {
                    missed++;
                    m = false;
                }
                writeSong(100, 'D');
                if (m == true)
                {
                    missed++;
                    m = false;
                }
                writeSong(50, 'F');
                if (m == true)
                {
                    missed++;
                    m = false;
                }
                writeSong(50, 'E');
                if (m == true)
                {
                    missed++;
                    m = false;
                }
                writeSong(100, 'D');
                if (m == true)
                {
                    missed++;
                    m = false;
                }
                done = true;
            }

            if (missed / 3 < 6)
            {
                uWon = true;
            }
            else
            {
                uWon = false;
            }
            state = 4;

            if (currKey == '#')
            {
                state = 5;
            }
            done = false;
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

    volatile unsigned int i, j; // volatile to prevent removal in optimization
                                // by compiler. Functionally this is useless code

    for (j = 0; j < numLoops; j++)
    {
        i = 50000;                 // SW Delay
        while (i > 0)               // could also have used while (i)
            i--;
    }
}

