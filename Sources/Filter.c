/*
 * Filter.c
 *
 *  Created on: Apr 26, 2019
 *      Author: Anderson
 */

#include "Filter.h"

char signed coeff[ORDER] = {-0,1,-2,3,-4,5,-6,7,-8,9};
char FilterIn[ORDER];
int FilterOut;

void UpdateCoeff(char *newcoeff) {
	char i;
	for (i = 0; i < ORDER; i++) {
		coeff[i] = newcoeff[i];
	}
}
