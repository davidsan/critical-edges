/*
 * scanner.c
 *
 *  Created on: 30 oct. 2012
 *      Author: david
 */
#include "scanner.h"

int scanInt(char * string) {
	int res = 0;
	if (sscanf(string, "%d", &res) != 1) {
		fprintf(stderr, "scanInt : erreur de format");
		return -1;
	}
	return res;
}
