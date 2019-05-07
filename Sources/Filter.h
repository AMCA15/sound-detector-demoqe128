/*
 * Filter.h
 *
 *  Created on: Apr 26, 2019
 *      Author: Anderson
 */

#ifndef FILTER_H_
#define FILTER_H_

#define ORDER 21

extern char FilterState;
extern signed char Coeff[];
extern char signed NewCoeff[];
extern char FilterIn[];
extern int FilterOut;

extern void UpdateCoeff(char *newcoeff);

#endif /* FILTER_H_ */
