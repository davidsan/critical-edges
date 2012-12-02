/**
 * \file convertPostscriptDijkstra.c
 * \brief Programme de conversion d'un ou plusieurs graphes avec calcul de Dijkstra vers PostScript
 * \author David San
 */

#include <stdio.h>
#include <libgen.h> /* basename function */
#include "reader.h"
#include "dijkstra.h"
#include "postscript.h"

int main(int argc, char **argv) {

	FILE * f = NULL;
	FILE * output = NULL;
	Graphe * G = NULL;
	char *filename = NULL;

	if (argc < 3 || (argc > 1 && (atoi(argv[1]) < 1 || atoi(argv[1]) > 4))) {
		fprintf(stderr, "usage: %s <datastruct> <gph-files>\n", argv[0]);
		fprintf(stderr, "\n");
		fprintf(stderr, "The datastruct parameters are:\n");
		fprintf(stderr, "   1 : Ordered linked list\n");
		fprintf(stderr, "   2 : Binary heap\n");
		fprintf(stderr, "   3 : Packets\n");
		fprintf(stderr, "   4 : Packets (circular storage)\n");
		return 1;
	}
	int i;
	for (i = 2; i < argc; i++) {
		f = ouvrirFichierRead(argv[i]);
		G = lectureGraphe(f);

		filename = basename(argv[i]);
		filename = strtok(filename, ".");
		filename = strcat(filename, ".ps");
		fprintf(stderr, "Converting %s to %s...\n", argv[i], filename);

		Dijkstra * D = NULL;
		switch (atoi(argv[1])) {
		case 2:
			fprintf(stderr, "Using a binary heap\n");
			D = dijkstraTas(G, G->s);
			break;
		case 3:
			fprintf(stderr, "Using packets\n");
			D = dijkstraPaquet(G, G->s);
			break;
		case 4:
			fprintf(stderr, "Using packets (circular storage)\n");
			D = dijkstraPaquetMod(G, G->s);
			break;
		default:
			fprintf(stderr, "Using an ordered linked list\n");
			D = dijkstraListe(G, G->s);
			break;
		}
		Arete * sp = extractSP(G, D);
		fprintf(stderr, "Cost of the shortest path (Dijsktra) : %d\n",
				calculCout(sp));

		output = ouvrirFichierWrite(filename);
		writeGraphe(output, G);
		writeDijkstra(output, G, sp);
		fermerFichier(output);

		freeArete(sp);
		freeDijkstra(D);
		fprintf(stderr, "Done.\n");
		fprintf(stderr, "\n");
		freeGraphe(G);
		if (f) {
			fermerFichier(f);
		}
	}

	fprintf(stderr, "All tasks completed.\n");
	free(filename);
	return 0;

}
