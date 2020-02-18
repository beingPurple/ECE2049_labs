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

    bool uWon = true;
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
            countdown();
            bool missed = false;
            int currtime = timer_cnt;
            int i;
            int el = timer_cnt - currtime;
            bool reset = false;

            tc = 0;

            while ((tc < 4) && (reset == false))
            {

                switch (tc)
                {
                case 0:
                    //play note, check for time
                    BuzzerOn(note2tune('E'));

                    break;
                case 1:
                    BuzzerOn(note2tune('D'));
                    break;
                case 2:
                    BuzzerOn(note2tune('C'));
                    break;
                }

                currKey = getKey();
                if (currKey == '#')
                {
                    state = 5;
                    reset = true;
                }

                if (missed)
                {
                    state = 4;
                    reset = true;
                }

            }
            BuzzerOff();
            uWon = true;
            state = 4;
            break;
        case 4:
            gameOver(uWon);
            state = 5;
            break;
        case 5:
            replay();
            uWon = false;
            state = 6;
            break;
        case 6:

            m = false;
            int n;
            countdown();

            int ctime = tc;
            int e = tc - ctime;
            while (m == false && currKey != '#' && tc - ctime < 4)
            {

                if (e < 1000)
                {
                    m = playSong('E');
                    currKey = getKey();
                }

                else if (e >= 1000 and e < 2000)
                {
                    m = playSong('D');
                    currKey = getKey();
                }

                else (e >= 2000 and e < 3000)
                {
                    m = playSong('C');
                    currKey = getKey();
                }

                uWon = true;
            }

            state = 4;
            if (currKey == '#')
            {
                state = 5;
            }

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

