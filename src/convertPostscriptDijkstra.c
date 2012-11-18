/**
 * \file convertPostscriptDijkstra.c
 * \brief Programme de conversion d'un ou plusieurs graphes avec calcul de Dijkstra vers PostScript
 * \author David San
 */

#include <stdio.h>
#include <libgen.h> /* basename function */
#include "reader.h"
#include "graph.h"
#include "postscript.h"
#include "dijkstra.h"
int main(int argc, char **argv) {

	FILE * f = NULL;
	FILE * output = NULL;
	Graphe * G = NULL;
	char *filename = NULL;

	if (argc < 2) {
		fprintf(stderr, "Usage : ./convertPostscriptDijkstra file.gph ...\n");
		return 1;
	}
	int i;
	for (i = 1; i < argc; i++) {
		f = ouvrirFichierRead(argv[i]);
		G = lectureGraphe(f);

		filename = basename(argv[i]);
		filename = strtok(filename, ".");
		filename = strcat(filename, ".ps");
		fprintf(stderr, "Converting %s to %s ...\n", argv[i], filename);
		Dijkstra * D = dijkstraListe(G, G->s);
		Arete * sp = extractSP(G, D);

		output = ouvrirFichierWrite(filename);
		writeGraphe(output, G);
		writeDijkstra(output, G, sp);
		fermerFichier(output);

		freeArete(sp);
		freeDijkstra(D);
		fprintf(stderr, "Done.\n");
		freeGraphe(G);
		if (f) {
			fermerFichier(f);
		}
	}

	fprintf(stderr, "All tasks completed.\n");
	free(filename);
	return 0;

}
