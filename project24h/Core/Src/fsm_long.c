/*
 * fsm_long.c
 *
 *  Created on: Nov 5, 2022
 *      Author: shiba
 */

#include"fsm_long.h"

void fsm_long_run() {
	switch (status) {
	case INC_LONG:
		//TODO
		if (is_button_pressed1s(1)) {
			setTimer0(10000);
			increase_time();
		}
		//Change mode

		//Change mode from INC_LONG to INC
		if (is_button_pressed(1)) {
			setTimer0(10000);
			increase_time();
			status = INC;
		}
		//Change mode from INC_LONG to DEC
		if (is_button_pressed(2)) {
			setTimer0(10000);
			decrease_time();
			status = DEC;
		}
		//Change from INC LONG to AUTO MODE after 10s have no interactive
		is_no_press_10s();
		//Reset time
		is_press_reset();
		break;
	case DEC_LONG:
		//TODO
		if (is_button_pressed1s(2)) {
			setTimer0(10000);
			decrease_time();
		}
		//Change mode

		//Change mode from DEC LONG to INC
		if (is_button_pressed(1)) {
			decrease_time();
			status = INC;
		}
		//Change mode from INC_LONG to DEC
		if (is_button_pressed(2)) {
			setTimer0(10000);
			decrease_time();
			status = DEC;
		}
		//Change from DEC LONG to AUTO MODE after 10s have no interactive
		is_no_press_10s();
		//Reset time
		is_press_reset();
		break;
	default:
		break;
	}
}
