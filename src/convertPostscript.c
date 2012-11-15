/**
 * \file convertPostscript.c
 * \brief Programme de conversion d'un ou plusieurs graphes vers PostScript
 * \author David San
 */

#include <stdio.h>
#include <libgen.h> /* basename function */
#include "reader.h"
#include "graph.h"
#include "postscript.h"

int main(int argc, char **argv) {

	FILE * f = NULL;
	Graphe * G = NULL;
	char *filename = NULL;

	if (argc < 2) {
		fprintf(stderr, "Usage : ./convertPostscript file.gph ...\n");
		return 1;
	}
	int i;
	for (i = 1; i < argc; i++) {
		f = ouvrirFichierRead(argv[i]);
		G = lectureGraphe(f);

		filename = basename(argv[i]);
		filename = strtok(filename, ".");
		filename = strcat(filename, ".ps");
		fprintf(stderr, "Converting %s to %s ...\n", basename(argv[i]),
				filename);
		writeGraphe(filename, G);
		fprintf(stderr, "Done.\n");
		freeGraphe(G);
		if (f) {
			fermerFichier(f);
		}
	}

	fprintf(stderr, "All tasks completed.\n");
	return 0;

}
