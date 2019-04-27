/*
 * Filter.h
 *
 *  Created on: Apr 26, 2019
 *      Author: Anderson
 */

#ifndef FILTER_H_
#define FILTER_H_

#define ORDER 10

extern signed char coeff[];
extern int FilterOut;

extern void UpdateCoeff(char *newcoeff);

#endif /* FILTER_H_ */
