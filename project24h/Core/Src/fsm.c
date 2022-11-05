/*
 * fsm.c
 *
 *  Created on: Nov 5, 2022
 *      Author: shiba
 */

#include"fsm.h"

void is_press_reset() {
	if (is_button_pressed(0)) {
		time = 0;
		status = AUTO_MODE;
		display7SEG(time);
	}
}

void increase_time() {
	time++;
	if (time > 9)
		time = 0;
	display7SEG(time);
}

void decrease_time(){
	time--;
	if (time < 0)
		time = 9;
	display7SEG(time);
}

void is_no_press_10s(){
	if (timer0_flag == 1) {
		timer0_flag = 0;
		status = AUTO_MODE;
		setTimer1(10);
	}
}

void fsm_run() {
	switch (status) {
	case INIT:
		display7SEG(time);
		setTimer1(1000);
		status = AUTO_MODE;
	case AUTO_MODE:
		//TODO
		if (time > 0 && timer1_flag == 1) {
			setTimer1(1000);
			time--;
			display7SEG(time);
		}
		//Change mode
		//Change from AUTO_MODE to INC
		if (is_button_pressed(1)) {
			setTimer0(10000);
			status = INC;
			increase_time();
		}
		//Change from AUTO_MODE to DEC
		if (is_button_pressed(2)) {
			setTimer0(10000);
			status = DEC;
			decrease_time();
		}
		//Reset time
		is_press_reset();
		break;
	case INC:
		//TODO
		if (is_button_pressed(1)) {
			setTimer0(10000);
			increase_time();
		}
		//Change mode

		//Change from INC to INC LONG
		if(is_button_pressed1s(1)){
			setTimer0(10000);
			increase_time();
			status = INC_LONG;
		}
		//Change from INC to AUTO MODE after 10s have no interactive
		is_no_press_10s();
		//Change from INC to DEC
		if (is_button_pressed(2)) {
			setTimer0(10000);
			decrease_time();
			status = DEC;
		}
		//Reset time
		is_press_reset();
		break;
	case DEC:
		//TODO
		if (is_button_pressed(2)) {
			setTimer0(10000);
			decrease_time();
		}
		//Change mode

		//Change from DEC to DEC LONG
		if(is_button_pressed1s(2)){
			setTimer0(10000);
			decrease_time();
			status = DEC_LONG;
		}
		//Change from DEC to AUTO MODE after 10s have no interactive
		is_no_press_10s();
		//Change from DEC to INC
		if (is_button_pressed(1)) {
			setTimer0(10000);
			increase_time();
			status = INC;
		}
		//Reset time
		is_press_reset();
		break;
	default:
		break;
	}
}
