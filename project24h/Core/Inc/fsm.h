/*
 * fsm.h
 *
 *  Created on: Nov 5, 2022
 *      Author: shiba
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

#include"led7Seg.h"
#include"global.h"
#include"timer.h"
#include"button.h"

void fsm_run();
void increase_time();
void decrease_time();
void is_press_reset();
void is_no_press_10s();

#endif /* INC_FSM_H_ */
