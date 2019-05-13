/*
 * Filter.c
 *
 *  Created on: Apr 26, 2019
 *      Author: Anderson
 */

#include "Filter.h"

char FilterState;
char fpos = 255;
// A High-Pass Filter with Fc = 0.4
char signed Coeff[ORDER] = {0, 0, 0, -1, -2, 0, 6, 6, -11, -38, 76, -38, -11, 6, 6, 0, -2, -1, 0, 0, 0};
char signed NewCoeff[ORDER];
char FilterIn[ORDER];
int FilterOut;

// Test Data
char TestNumber;
char TestData[TESTSIZE] = {104, 116, 17, 116, 81, 13, 36, 70, 122, 123, 21, 124, 122, 62, 102, 19, 54, 117, 101, 122, 84, 5, 108, 119, 87, 97, 95, 50, 84, 22, 90, 5, 36, 6, 13, 105, 89, 41, 121, 5, 56, 49, 98, 101, 24, 63, 57, 83, 91, 96};
int TestDataFiltered[TESTSIZE] = {0, 0, 0, -104, -324, -249, 474, 1007, -521, -4492, 4349, 3244, -9632, 4666, 2977, -3606, -1503, -690, 2978, 2837, -9357, 3391, 2350, -3987, 4429, -4125, -1457, 2375, -2159, 2165, 1015, -7479, 3788, 2196, -2995, -480, 1419, -2624, 2611, -4786, 4966, -3688, 2451, -1425, -3442, 4265, -139, -5656, 7255, -5209};

void UpdateCoeff(char *newcoeff) {
	char i;
	for (i = 0; i < ORDER; i++) {
		Coeff[i] = newcoeff[i];
	}
}
