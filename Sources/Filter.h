/*
 * Filter.h
 *
 *  Created on: Apr 26, 2019
 *      Author: Anderson
 */

#ifndef FILTER_H_
#define FILTER_H_

#define ORDER 21

#define FILTERTEST    // Uncomment for use the filter test mode
#define TESTSIZE 50

extern char FilterState;
extern char fpos;
extern signed char Coeff[];
extern char signed NewCoeff[];
extern char FilterIn[];
extern int FilterOut;

// Test Data
extern char TestNumber;
extern char TestData[];
extern int TestDataFiltered[];

extern void UpdateCoeff(char *newcoeff);

#endif /* FILTER_H_ */
