/*
 * leg7Seg.c
 *
 *  Created on: Nov 3, 2022
 *      Author: shiba
 */

#include"led7Seg.h"

void display7SEG(int num) {
	switch (num) {
//		using output data register to set value for port B
	case 0: {
//			using operator & with 0xFF00 to reset 7bits low
		GPIOB->ODR &= 0xFF80;
//			set value to 8bits low by using operator & to retain 8bits high
		GPIOB->ODR |= 0x0040;
		break;
	}
	case 1: {
		GPIOB->ODR &= 0xFF80;
		GPIOB->ODR |= 0x0079;
		break;
	}
	case 2: {
		GPIOB->ODR &= 0xFF80;
		GPIOB->ODR |= 0x0024;
		break;
	}
	case 3: {
		GPIOB->ODR &= 0xFF80;
		GPIOB->ODR |= 0x0030;
		break;
	}
	case 4: {
		GPIOB->ODR &= 0xFF80;
		GPIOB->ODR |= 0x0019;
		break;
	}
	case 5: {
		GPIOB->ODR &= 0xFF80;
		GPIOB->ODR |= 0x0012;
		break;
	}
	case 6: {
		GPIOB->ODR &= 0xFF80;
		GPIOB->ODR |= 0x0002;
		break;
	}
	case 7: {
		GPIOB->ODR &= 0xFF80;
		GPIOB->ODR |= 0x0078;
		break;
	}
	case 8: {
		GPIOB->ODR &= 0xFF80;
		GPIOB->ODR |= 0x0000;
		break;
	}
	case 9: {
		GPIOB->ODR &= 0xFF80;
		GPIOB->ODR |= 0x0010;
		break;
	}
	default:
		GPIOB->ODR &= 0xFF80;
		break;
	}
}


