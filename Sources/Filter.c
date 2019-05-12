/*
 * Filter.c
 *
 *  Created on: Apr 26, 2019
 *      Author: Anderson
 */

#include "Filter.h"

char FilterState;
// A High-Pass Filter with Fc = 0.4
char signed Coeff[ORDER] = {0, 0, 0, -1, -2, 0, 6, 6, -11, -38, 76, -38, -11, 6, 6, 0, -2, -1, 0, 0, 0};
char signed NewCoeff[ORDER];
char FilterIn[ORDER];
int FilterOut;

// Test Data
char TestNumber;
char TestData[TESTSIZE] = {116, 81, 13, 36, 70, 122, 123, 21, 124, 122, 62, 102, 19, 54, 117, 101, 122, 84, 5, 108, 119};
int TestDataFiltered[TESTSIZE] = {0, 0, 0, -116, -313, -175, 634, 1040, -974, -5372, 5964, 1844, -4404, -1397, -354, 3128, 2854, -9357, 3391, 2350, -3987};

void UpdateCoeff(char *newcoeff) {
	char i;
	for (i = 0; i < ORDER; i++) {
		Coeff[i] = newcoeff[i];
	}
}
