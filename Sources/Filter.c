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
char signed Coeff[ORDER] = {0,   0,   0,  0, 0, 0,  0,  0, 0, -1, 0,   1,   1,
                            -1,  -2,  0,  3, 2, -3, -6, 0, 9, 8,  -12, -39, 77,
                            -39, -12, 8,  9, 0, -6, -3, 2, 3, 0,  -2,  -1,  1,
                            1,   0,   -1, 0, 0, 0,  0,  0, 0, 0,  0,   0};
char signed NewCoeff[ORDER];
char FilterIn[ORDER];
int FilterOut;

// Test Data
char TestNumber;
char TestData[TESTSIZE] = {
    92,  80, 44, 120, 16,  94,  83, 107, 51,  96,  107, 42,  71,  126, 71,
    43,  80, 47, 97,  53,  64,  89, 125, 42,  108, 95,  123, 5,   46,  85,
    37,  30, 92, 80,  76,  85,  7,  45,  58,  31,  92,  110, 37,  94,  18,
    108, 18, 76, 47,  104, 65,  63, 113, 46,  58,  124, 6,   125, 25,  86,
    76,  87, 47, 80,  104, 3,   11, 125, 84,  30,  52,  16,  35,  34,  43,
    20,  45, 16, 114, 13,  120, 52, 7,   44,  95,  102, 70,  88,  115, 8,
    39,  6,  26, 93,  93,  113, 75, 10,  119, 103};
int TestDataFiltered[TESTSIZE] = {
    0,     0,     0,     0,     0,     0,     0,     0,     0,     -92,
    -80,   48,    52,    16,    -194,  -151,  71,    294,   -16,   -564,
    -492,  385,   950,   -216,  -3664, 4073,  -93,   -4760, 6464,  -6189,
    2851,  -449,  1640,  -5037, 1980,  3971,  -4839, -1936, 4971,  -1253,
    -3400, 2241,  -2060, 3547,  -2949, -1884, 973,   4831,  -6855, 1026,
    2,     5475,  -7491, -536,  5144,  -1356, -3654, 2368,  -689,  -931,
    2638,  -4447, 1865,  2200,  -4433, 1093,  3010,  -4945, 3781,  -5253,
    6462,  -5061, 1940,  -2704, 3526,  -2049, -2468, 4602,  -3622, -1752,
    6632,  -8655, 6882,  -5501, 2347,  403,   545,   -4832, 987,   6683,
    -5061, -5317, 6767,  388,   -4519, 1814,  -850,  941,   -730,  238};

void UpdateCoeff(char *newcoeff) {
	char i;
	for (i = 0; i < ORDER; i++) {
		Coeff[i] = newcoeff[i];
	}
}
