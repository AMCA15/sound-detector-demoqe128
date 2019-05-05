/*
 * Filter.c
 *
 *  Created on: Apr 26, 2019
 *      Author: Anderson
 */

#include "Filter.h"

char FilterState;
char signed Coeff[ORDER] = { -0, 1, -2, 3, -4, 5, -6, 7, -8, 9 };
char signed NewCoeff[ORDER];
char FilterIn[ORDER];
int FilterOut;

void UpdateCoeff(char *newcoeff) {
	char i;
	for (i = 0; i < ORDER; i++) {
		Coeff[i] = newcoeff[i];
	}
}
