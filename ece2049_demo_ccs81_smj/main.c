#include <msp430.h>
#include "peripherals.h"
#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void swDelay(char numLoops);
void setTimer(int ms_delay);
void runtimerA2(void);
void stoptimerA2(int reset);
char intToChar(int ledOn);
void turnOnLED(int ledOn);
void fillSong1(void); // Star Song
void fillSong2(void); // Hit Or Miss

// Declare globals here
int song[28][3], song2[50][3]; //holds all the notes
long unsigned int timer_cnt = 0;
long unsigned int cycles = 200; // how many rounds the timer should go for before completing task
bool timer_done = false;
char tdir = 1;
unsigned char currKey = 0, currButton = 0, currNote = 0;
int state = 0; //state of the state machine

// Main
void main(void)
{
    int countdown_state = 3; //state of the countdown state machine
    bool hitNote = false;
    int fails = 0;
    int i, songNum;


    WDTCTL = WDTPW | WDTHOLD;
    initLeds();

    fillSong1();
    fillSong2();
    configDisplay();
    configKeypad();
    configButtons();

    Graphics_clearDisplay(&g_sContext);

    _BIS_SR(GIE); // Global interrupt enable
    runtimerA2();

        while(1){
        currKey = getKey();
        currButton = stateButtons();

        switch(state){
            case 0:// Welcome screen

                Graphics_drawStringCentered(&g_sContext, "Welcome to", AUTO_STRING_LENGTH, 48, 15,TRANSPARENT_TEXT);
                Graphics_drawStringCentered(&g_sContext, "MSP430 Hero", AUTO_STRING_LENGTH, 48, 25,TRANSPARENT_TEXT);
                Graphics_drawStringCentered(&g_sContext, "Press *" , AUTO_STRING_LENGTH, 48, 45,TRANSPARENT_TEXT);
                Graphics_drawStringCentered(&g_sContext, "to Start" , AUTO_STRING_LENGTH, 48, 55,TRANSPARENT_TEXT);
                Graphics_flushBuffer(&g_sContext);

                if (currKey == '*'){
                    Graphics_clearDisplay(&g_sContext);
                    countdown_state = 3;
                    state = 5;
                    fails = 0;
                }
                break;

            case 1: // Count down

                switch(countdown_state) {
                case 3: // Count down - 3
                    Graphics_clearDisplay(&g_sContext);
                    setTimer(1000);

                    P4OUT ^= BIT7;
                    P1OUT ^= BIT0;

                    Graphics_drawStringCentered(&g_sContext, "3" , AUTO_STRING_LENGTH, 48, 48,TRANSPARENT_TEXT);
                    Graphics_flushBuffer(&g_sContext);

                    while(!timer_done){}

                    countdown_state = 2;
                    break;

                case 2: // count down - 2
                    Graphics_clearDisplay(&g_sContext);
                    setTimer(1000);

                    P4OUT ^= BIT7;

                    Graphics_drawStringCentered(&g_sContext, "2" , AUTO_STRING_LENGTH, 48, 48,TRANSPARENT_TEXT);
                    Graphics_flushBuffer(&g_sContext);

                    while(!timer_done){}

                    countdown_state = 1;
                    break;

               case 1: // count down - 1
                   Graphics_clearDisplay(&g_sContext);
                   setTimer(1000);

                   P4OUT ^= BIT7;
                   P1OUT ^= BIT0;

                   Graphics_drawStringCentered(&g_sContext, "1" , AUTO_STRING_LENGTH, 48, 48,TRANSPARENT_TEXT);
                   Graphics_flushBuffer(&g_sContext);

                   while(!timer_done){}

                   countdown_state = 0;
                   break;

                case 0: // Count down - go
                    Graphics_clearDisplay(&g_sContext);
                    setTimer(1000);
                    Graphics_drawStringCentered(&g_sContext, "GO" , AUTO_STRING_LENGTH, 48, 48,TRANSPARENT_TEXT);
                    Graphics_flushBuffer(&g_sContext);

                    P4OUT ^= BIT7;

                    while(!timer_done){}

                    if (timer_done)
                    {
                        Graphics_clearDisplay(&g_sContext);
                        state = 2;
                    }
                    break;

                }
                break;

            case 2: // Gameplay case
                if(songNum == 1){
                    for(i = 0; i < 28; i++){
                        turnOnLED(song[i][2]);
                        setTimer(song[i][1]);
                        while(!timer_done){
                            currButton = stateButtons();
                            currNote   = intToChar(song[i][2]);
                            if (currButton == currNote){
                                BuzzerOn(song[i][0]);
                                hitNote = true;
                            }
                            else if(hitNote){
                                BuzzerOn(song[i][0]);
                                hitNote = true;
                            }
                            else{
                                BuzzerOff();
                            }


                            if(state != 2){
                                BuzzerOff();
                                turnOnLED(0);
                                break;
                            }
                        }

                        turnOnLED(0);
                        BuzzerOff();
                        setTimer(150);

                        if(!hitNote){
                            fails++;
                            BuzzerOff();
                        }
                        hitNote = false;

                        if(fails >= 3){//check to see if they failed too much
                            state = 3;
                            break;
                        }
                        while(!timer_done) {
                            if(state != 2){
                                BuzzerOff();
                                turnOnLED(0);
                                break;
                            }
                            //delay the code
                        }

                        if(state != 2){
                            BuzzerOff();
                            turnOnLED(0);
                            break;
                        }
                    }// end of for loop
                }// end of song 1 if
                else if (songNum == 2){
                    for(i = 0; i < 50; i++){
                        turnOnLED(song2[i][2]);
                        setTimer(song2[i][1]+250);

                        while(!timer_done){
                            currButton = stateButtons();
                            currNote   = intToChar(song2[i][2]);

                            if (currButton == currNote){
                                BuzzerOn(song2[i][0]);
                                hitNote = true;
                            }

                            else if(hitNote){
                                BuzzerOn(song2[i][0]);
                                hitNote = true;
                            }

                            else{
                                BuzzerOff();
                            }

                            if(state != 2){
                                BuzzerOff();
                                turnOnLED(0);
                                break;
                            }
                        }

                        turnOnLED(0);
                        BuzzerOff();
                        setTimer(150);

                        if(!hitNote){
                            fails++;
                            BuzzerOff();
                        }

                        hitNote = false;

                        if(fails >= 3){ // Check to see if they failed
                            state = 6;
                            break;
                        }

                        while(!timer_done) {
                            if(state != 2){
                                BuzzerOff();
                                turnOnLED(0);
                                break;
                            }
                            // Delay the code
                        }

                        if(state != 2){
                            BuzzerOff();
                            turnOnLED(0);
                            break;
                        }
                    }   // End of for loop
                }

                // Determines if you win
                if(fails < 3 && state == 2){
                state = 4;
                }
                break;

            case 3://lose case
                Graphics_drawStringCentered(&g_sContext, "YoU lOsT?", AUTO_STRING_LENGTH, 48, 15,TRANSPARENT_TEXT);
                Graphics_drawStringCentered(&g_sContext, "tHaT WaS eAsY", AUTO_STRING_LENGTH, 48, 25,TRANSPARENT_TEXT);
                Graphics_drawStringCentered(&g_sContext, "Press * to" , AUTO_STRING_LENGTH, 48, 45,TRANSPARENT_TEXT);
                Graphics_drawStringCentered(&g_sContext, "Lose Again" , AUTO_STRING_LENGTH, 48, 55,TRANSPARENT_TEXT);
                Graphics_flushBuffer(&g_sContext);

                if (currKey == '*'){
                    Graphics_clearDisplay(&g_sContext);
                    state = 0;
                }
                break;

            case 4:// win case
                Graphics_drawStringCentered(&g_sContext, "You Have WON!", AUTO_STRING_LENGTH, 48, 15,TRANSPARENT_TEXT);
                Graphics_drawStringCentered(&g_sContext, "Press *" , AUTO_STRING_LENGTH, 48, 45,TRANSPARENT_TEXT);
                Graphics_drawStringCentered(&g_sContext, "Play again" , AUTO_STRING_LENGTH, 48, 55,TRANSPARENT_TEXT);
                Graphics_flushBuffer(&g_sContext);

                if (currKey == '*'){
                    Graphics_clearDisplay(&g_sContext);
                    state = 0;
                }
                break;

            case 5: // Addition: Menu screen to choose a song
                Graphics_drawStringCentered(&g_sContext, "Push The Number" , AUTO_STRING_LENGTH, 48, 15,TRANSPARENT_TEXT);
                Graphics_drawStringCentered(&g_sContext, "of the Song" , AUTO_STRING_LENGTH, 48, 25,TRANSPARENT_TEXT);
                Graphics_drawStringCentered(&g_sContext, "1)TwinkleTwinkle" , AUTO_STRING_LENGTH, 48, 55,TRANSPARENT_TEXT);
                Graphics_drawStringCentered(&g_sContext, "2) Hit or Miss" , AUTO_STRING_LENGTH, 48, 65,TRANSPARENT_TEXT);
                Graphics_flushBuffer(&g_sContext);

                if (currKey == '1'){
                    songNum = 1;
                    state = 1;
                }

                else if (currKey == '2'){
                    songNum = 2;
                    state = 1;
                }

                break;

            case 6: // Additon: Lose screen for hit or miss TikTok song :P
                Graphics_drawStringCentered(&g_sContext, "i gUeSs yOu", AUTO_STRING_LENGTH, 48, 15,TRANSPARENT_TEXT);
                Graphics_drawStringCentered(&g_sContext, "mIsSeD, hUH?", AUTO_STRING_LENGTH, 48, 25,TRANSPARENT_TEXT);
                Graphics_drawStringCentered(&g_sContext, "bEt uR bOyFrIeNd", AUTO_STRING_LENGTH, 48, 35,TRANSPARENT_TEXT);
                Graphics_drawStringCentered(&g_sContext, "nEv3R kIsSeD YaA", AUTO_STRING_LENGTH, 48, 45,TRANSPARENT_TEXT);
                Graphics_drawStringCentered(&g_sContext, "Press * to" , AUTO_STRING_LENGTH, 48, 65,TRANSPARENT_TEXT);
                Graphics_drawStringCentered(&g_sContext, "Lose Again" , AUTO_STRING_LENGTH, 48, 75,TRANSPARENT_TEXT);
                Graphics_flushBuffer(&g_sContext);

                if (currKey == '*'){
                    Graphics_clearDisplay(&g_sContext);
                    state = 0;
                }

                break;
        } // End of state machine

    }  // End while (1)

}

void swDelay(char numLoops)
{

    volatile unsigned int i,j;  // volatile to prevent removal in optimization
                                // by compiler. Functionally this is useless code

    for (j=0; j<numLoops; j++)
    {
        i = 50000 ;                 // SW Delay
        while (i > 0)               // could also have used while (i)
           i--;
    }
}

/**
 * Set the delay to a certain amount and convert ms needed to cycles the A2 timer can process
 */
char intToChar(int ledOn){
    char setter;
        setter = 0x0;
        if(ledOn == 4){
            setter = 0x8;
        }
        else if(ledOn == 3){
            setter = 0x4;
        }
        else if(ledOn == 2){
            setter = 0x2;
        }
        else if(ledOn == 1){
            setter = 0x1;
        }
        return setter;
}
void turnOnLED(int ledOn){
    char setter;
    setter = 0x0;
    if(ledOn == 1){
        setter = 0x8;
    }
    if(ledOn == 2){
        setter = 0x4;
    }
    if(ledOn == 3){
        setter = 0x2;
    }
    if(ledOn == 4){
        setter = 0x1;
    }
    setLeds(setter);
}

void setTimer(int ms_delay) {
    timer_cnt = 0;
    cycles = ms_delay / 5;
    timer_done = false;
}

void runtimerA2(void)
{
    // Function configures and starts Timer A2
    // Timer is counting -0.005 seconds

    TA2CTL = TASSEL_1 + MC_1 + ID_0;
    TA2CCR0 = 163; // 163 + 1 = 164 ACLK tick = ~5/1000 seconds
    TA2CCTL0 = CCIE; // TA2CCR0 interrupt enabled
}

void stoptimerA2(int reset)
{
    // Function stops Timer A2 and resets global time var if input = 1

    TA2CTL = MC_0; // stop timer
    TA2CCTL0 &= ~CCIE; // TA2CCR0 interrupt disabled

    if(reset)
        timer_cnt=0;
}

// Timer A2 interrupt service routine
#pragma vector=TIMER2_A0_VECTOR
__interrupt void TimerA2_ISR (void)
{
    if(tdir)
    {
        timer_cnt++;
        currKey = getKey();
        if(currKey == '#'){
           state = 0;
           Graphics_clearDisplay(&g_sContext);
        }
        if (timer_cnt == cycles) {
            timer_cnt = 0;
            timer_done = true;
        }
        /* Test for timer
        if (timer_cnt%200 == 0) // blink LEDs once a second
        {
            P1OUT = P1OUT ^ BIT0;
            P4OUT ^= BIT7;
        }
        */
    }
    else
        timer_cnt--;
}

void fillSong1(void){
    //twinkle twinkle little star

    //G,G,D,D,E,E,D
    song[0][0] = 784; song[0][1] = 600; song[0][2] = 4;

    song[1][0] = 784; song[1][1] = 600; song[1][2] = 4;

    song[2][0] = 587; song[2][1] = 600; song[2][2] = 2;

    song[3][0] = 587; song[3][1] = 600; song[3][2] = 2;

    song[4][0] = 659; song[4][1] = 600; song[4][2] = 3;

    song[5][0] = 659; song[5][1] = 600; song[5][2] = 3;

    song[6][0] = 587; song[6][1] = 1200; song[6][2] = 2;

    //C,C,B,B,A,A,G

    song[7][0] = 523; song[7][1] = 600; song[7][2] = 1;

    song[8][0] = 523; song[8][1] = 600; song[8][2] = 1;

    song[9][0] = 494; song[9][1] = 600; song[9][2] = 2;

    song[10][0] = 494; song[10][1] = 600; song[10][2] = 2;

    song[11][0] = 440; song[11][1] = 600; song[11][2] = 1;

    song[12][0] = 440; song[12][1] = 600; song[12][2] = 1;

    song[13][0] = 784; song[13][1] = 1200; song[13][2] = 4;

    //D,D,C,C,B,B,A

    song[14][0] = 587; song[14][1] = 600; song[14][2] = 2;

    song[15][0] = 587; song[15][1] = 600; song[15][2] = 2;

    song[16][0] = 523; song[16][1] = 600; song[16][2] = 1;

    song[17][0] = 523; song[17][1] = 600; song[17][2] = 1;

    song[18][0] = 494; song[18][1] = 600; song[18][2] = 2;

    song[19][0] = 494; song[19][1] = 600; song[19][2] = 2;

    song[20][0] = 440; song[20][1] = 1200; song[20][2] = 1;

    //D,D,C,C,B,F,B flat

    song[21][0] = 587; song[21][1] = 600; song[21][2] = 2;

    song[22][0] = 587; song[22][1] = 600; song[22][2] = 2;

    song[23][0] = 523; song[23][1] = 600; song[23][2] = 1;

    song[24][0] = 523; song[24][1] = 600; song[24][2] = 1;

    song[25][0] = 494; song[25][1] = 600; song[25][2] = 2;

    song[26][0] = 698; song[26][1] = 600; song[26][2] = 4;

    song[27][0] = 466; song[27][1] = 1200; song[27][2] = 3;
}

void fillSong2(void) {
    // Hit or Miss :P

    // E E F D E E
    song2[0][0] = 659; song2[0][1]= 214; song2[0][2] = 3;
    song2[1][0] = 659; song2[1][1]= 214; song2[1][2] = 3;
    song2[2][0] = 698; song2[2][1]= 643; song2[2][2] = 4;
    song2[3][0] = 587; song2[3][1]= 214; song2[3][2] = 2;
    song2[4][0] = 659; song2[4][1]= 214; song2[4][2] = 3;
    song2[5][0] = 659; song2[5][1]= 214; song2[5][2] = 3;

    // E E F D R E
    song2[6][0] = 659; song2[6][1]= 214; song2[6][2] = 3;
    song2[7][0] = 659; song2[7][1]= 214; song2[7][2] = 3;
    song2[8][0] = 698; song2[8][1]= 429; song2[8][2] = 4;
    song2[9][0] = 587; song2[9][1]= 429; song2[9][2] = 2;
    song2[10][0] = 0; song2[10][1]= 321; song2[10][2] = 0;
    song2[11][0] = 659; song2[11][1]= 107; song2[11][2] = 3;

    // E E F D D G
    song2[12][0] = 659; song2[12][1]= 214; song2[12][2] = 3;
    song2[13][0] = 659; song2[13][1]= 214; song2[13][2] = 3;
    song2[14][0] = 698; song2[14][1]= 429; song2[14][2] = 4;
    song2[15][0] = 587; song2[15][1]= 214; song2[15][2] = 2;
    song2[16][0] = 587; song2[16][1]= 214; song2[16][2] = 2;
    song2[17][0] = 784; song2[17][1]= 214; song2[17][2] = 4;

    // G A A B A R
    song2[18][0] = 784; song2[18][1]= 214; song2[18][2] = 4;
    song2[19][0] = 440; song2[19][1]= 214; song2[19][2] = 1;
    song2[20][0] = 440; song2[20][1]= 214; song2[20][2] = 1;
    song2[21][0] = 494; song2[21][1]= 429; song2[21][2] = 2;
    song2[22][0] = 440; song2[22][1]= 429; song2[22][2] = 1;
    song2[23][0] = 0; song2[23][1]= 429; song2[23][2] = 0;

    // F F F F F F
    song2[24][0] = 698; song2[24][1]= 214; song2[24][2] = 4;
    song2[25][0] = 698; song2[25][1]= 214; song2[25][2] = 4;
    song2[26][0] = 698; song2[26][1]= 214; song2[26][2] = 4;
    song2[27][0] = 698; song2[27][1]= 214; song2[27][2] = 4;
    song2[28][0] = 698; song2[28][1]= 214; song2[28][2] = 4;
    song2[29][0] = 698; song2[29][1]= 214; song2[29][2] = 4;

    // F F G A C B
    song2[30][0] = 698; song2[30][1]= 214; song2[30][2] = 4;
    song2[31][0] = 698; song2[31][1]= 214; song2[31][2] = 4;
    song2[32][0] = 784; song2[32][1]= 214; song2[32][2] = 4;
    song2[33][0] = 440; song2[33][1]= 214; song2[33][2] = 1;
    song2[34][0] = 523; song2[34][1]= 429; song2[34][2] = 1;
    song2[35][0] = 494; song2[35][1]= 429; song2[35][2] = 2;

    // R A A A A A
    song2[36][0] = 0; song2[36][1]= 429; song2[36][2] = 0;
    song2[37][0] = 440; song2[37][1]= 214; song2[37][2] = 1;
    song2[38][0] = 440; song2[38][1]= 214; song2[38][2] = 1;
    song2[39][0] = 440; song2[39][1]= 214; song2[39][2] = 1;
    song2[40][0] = 440; song2[40][1]= 214; song2[40][2] = 1;
    song2[41][0] = 440; song2[41][1]= 214; song2[41][2] = 1;

    // A A A B A C
    song2[42][0] = 440; song2[42][1]= 214; song2[42][2] = 1;
    song2[43][0] = 440; song2[43][1]= 214; song2[43][2] = 1;
    song2[44][0] = 440; song2[44][1]= 214; song2[44][2] = 1;
    song2[45][0] = 494; song2[45][1]= 214; song2[45][2] = 2;
    song2[46][0] = 440; song2[46][1]= 214; song2[46][2] = 1;
    song2[47][0] = 523; song2[47][1]= 429; song2[47][2] = 1;

    // B R
    song2[48][0] = 494; song2[48][1]= 429; song2[48][2] = 2;
    song2[49][0] = 0; song2[49][1]= 429; song2[49][2] = 0;

}
