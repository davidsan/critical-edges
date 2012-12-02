/**
 * \file convertTimer.c
 * \brief Programme de statistiques sur la conversion d'un ou plusieurs graphes avec calcul de l'arête vitale vers PostScript
 * \author David San
 */

#include <stdio.h>
#include <libgen.h> /* basename function */
#include "timer.h"

int main(int argc, char **argv) {

	if (argc < 3 || (argc > 1 && (atoi(argv[1]) < 1 || atoi(argv[1]) > 5))) {
		fprintf(stderr, "usage: %s <datastruct> <gph-files>\n", argv[0]);
		fprintf(stderr, "\n");
		fprintf(stderr, "The datastruct parameters are:\n");
		fprintf(stderr, "   1 : Ordered linked list\n");
		fprintf(stderr, "   2 : Binary heap\n");
		fprintf(stderr, "   3 : Packets\n");
		fprintf(stderr, "   4 : Packets (circular storage)\n");
		fprintf(stderr, "   5 : All\n");
		return 1;
	}
	int i;
	for (i = 2; i < argc; i++) {
		switch (atoi(argv[1])) {
		case 1:
			timeListe(argv[i]);
			break;
		case 2:
			timeTas(argv[i]);
			break;
		case 3:
			timePaquet(argv[i]);
			break;
		case 4:
			timePaquetMod(argv[i]);
			break;
		default:
			timeAll(argv[i]);
			break;
		}
	}
	return 0;

}

