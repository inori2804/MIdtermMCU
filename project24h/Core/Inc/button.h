/*
 * button.h
 *
 *  Created on: Nov 3, 2022
 *      Author: shiba
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "global.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

extern int button0_flag;
extern int button1_flag;
extern int button2_flag;

extern int button0_pressed1s_flag;
extern int button1_pressed1s_flag;
extern int button2_pressed1s_flag;

unsigned char is_button_pressed(int index);

unsigned char is_button_pressed1s(int index);

void getKeyInput();

#endif /* INC_BUTTON_H_ */
