/*
 * Filter.c
 *
 *  Created on: Apr 26, 2019
 *      Author: Anderson
 */

#include "Filter.h"

char FilterState;
// A High-Pass Filter with Fc = 0.4
char signed Coeff[ORDER] = {0, 0, -1, -2, -1, 4, 9, 2, -23, -54, 127, -54, -23, 2, 9, 4, -1, -2, -1, 0, 0};
char signed NewCoeff[ORDER];
char FilterIn[ORDER];
int FilterOut;

void UpdateCoeff(char *newcoeff) {
	char i;
	for (i = 0; i < ORDER; i++) {
		Coeff[i] = newcoeff[i];
	}
}
