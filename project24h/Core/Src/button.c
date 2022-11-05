/*
 * button.c
 *
 *  Created on: Nov 3, 2022
 *      Author: shiba
 */

#include<button.h>

#define numberOfButton		3

int KeyReg0[numberOfButton] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE };
int KeyReg1[numberOfButton] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE };
int KeyReg2[numberOfButton] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE };
int KeyReg3[numberOfButton] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE };

int button0_flag = 0;
int button1_flag = 0;
int button2_flag = 0;

int button0_pressed1s_flag = 0;
int button1_pressed1s_flag = 0;
int button2_pressed1s_flag = 0;

int TimeOutForKeyPress[3] = {300, 300 ,300};

void subKeyProcess(int i) {
	//TODO
	if (i == 0) {
		button0_flag = 1;
	} else if (i == 1) {
		button1_flag = 1;
	} else if (i == 2) {
		button2_flag = 1;
	}
}

void pressed_1s_process(int i) {
	//TODO
	if (i == 0) {
		button0_pressed1s_flag = 1;
	} else if (i == 1) {
		button1_pressed1s_flag = 1;
	} else if (i == 2) {
		button2_pressed1s_flag = 1;
	}
}

void getKeyInput() {
	for (unsigned char i = 0; i < numberOfButton; i++) {
//		Logic to prevent bounce is using 3 layers
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
//		Read input pin
		if (i == 0) {
			KeyReg0[i] = HAL_GPIO_ReadPin(BUTTON_0_GPIO_Port, BUTTON_0_Pin);
		} else if (i == 1) {
			KeyReg0[i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
		} else if (i == 2) {
			KeyReg0[i] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
		}
//		Handle press and press one second
		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])) {
			if (KeyReg2[i] != KeyReg3[i]) {
				KeyReg3[i] = KeyReg2[i];

				if (KeyReg3[i] == PRESSED_STATE) {
					TimeOutForKeyPress[i] = 300;
					subKeyProcess(i); // is pressed
				}
			} else {
				TimeOutForKeyPress[i]--;
				if (TimeOutForKeyPress[i] == 0) {
					if (KeyReg2[i] == PRESSED_STATE) {
						pressed_1s_process(i); // is pressed one second
					}
					TimeOutForKeyPress[i] = 100;
				}
			}
		}
	}
}

unsigned char is_button_pressed(int index) {
	switch (index) {
	case 0:
		if (button0_flag == 1) {
			button0_flag = 0;
			return 1;
		}
		break;
	case 1:
		if (button1_flag == 1) {
			button1_flag = 0;
			return 1;
		}
		break;
	case 2:
		if (button2_flag == 1) {
			button2_flag = 0;
			return 1;
		}
		break;
	default:
		break;
	}
	return 0;
}

unsigned char is_button_pressed1s(int index) {
	switch (index) {
	case 0:
		if (button0_pressed1s_flag == 1) {
			button0_pressed1s_flag = 0;
			return 1;
		}
		break;
	case 1:
		if (button1_pressed1s_flag == 1) {
			button1_pressed1s_flag = 0;
			return 1;
		}
		break;
	case 2:
		if (button2_pressed1s_flag == 1) {
			button2_pressed1s_flag = 0;
			return 1;
		}
		break;
	default:
		break;
	}
	return 0;
}
