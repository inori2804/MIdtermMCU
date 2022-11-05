/*
 * timer.c
 *
 *  Created on: Nov 3, 2022
 *      Author: shiba
 */

#include"timer.h"

int TIMER_CYCLE = 10; // timer cycle need change when we modify time interrupt

int timer0_flag = 0;
int timer0_counter = 0;

int timer1_flag = 0;
int timer1_counter = 0;

int timer2_flag = 0;
int timer2_counter = 0;

// function to set counter for timer0
void setTimer0(int duration) {
	timer0_flag = 0;
	timer0_counter = duration / TIMER_CYCLE;
}
// function to set counter for timer1
void setTimer1(int duration) {
	timer1_flag = 0;
	timer1_counter = duration / TIMER_CYCLE;
}
// function to set counter for timer2
void setTimer2(int duration) {
	timer2_flag = 0;
	timer2_counter = duration / TIMER_CYCLE;
}

// run timer
void timerRun() {
	if (timer0_counter > 0) {
		timer0_counter--;
		if (timer0_counter <= 0) {
			timer0_flag = 1;
		}
	}
	if (timer1_counter > 0) {
		timer1_counter--;
		if (timer1_counter <= 0) {
			timer1_flag = 1;
		}
	}
	if (timer2_counter > 0) {
			timer2_counter--;
			if (timer2_counter <= 0) {
				timer2_flag = 1;
			}
		}
}

