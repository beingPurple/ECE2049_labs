/*
 * song.h
 *
 *  Created on: Feb 17, 2020
 *      Author: ncmorgan
 */

#ifndef SONG_H_
#define SONG_H_

void countdown();
void blindMice();
void playSong(char note, int currTime, int duration);
int note2tune(char note);
void writeSong(int dur, char note);

#endif /* SONG_H_ */
