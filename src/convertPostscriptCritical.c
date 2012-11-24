/**
 * \file convertPostscriptCrtiical
 * \brief Programme de conversion d'un ou plusieurs graphes avec calcul de l'arête vitale vers PostScript
 * \author David San
 */

#include <stdio.h>
#include <libgen.h> /* basename function */
#include "reader.h"
#include "graph.h"
#include "postscript.h"
#include "dijkstra.h"
#include "solver.h"

int main(int argc, char **argv) {

	FILE * f = NULL;
	FILE * output = NULL;
	Graphe * G = NULL;
	char *filename = NULL;

	if (argc < 2) {
		fprintf(stderr, "Usage : ./convertPostscriptCritical file.gph ...\n");
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
		Dijkstra * D = NULL;
		D = dijkstraListe(G, G->s);
		// D = dijkstraTas(G, G->s);
		// D = dijkstraPaquet(G, G->s);
		Arete * sp = extractSP(G, D);
		Arete * vitale = NULL;

		vitale = solveListe(G, sp);
		//	vitale = solveTas(G, sp);
		//	vitale = solvePaquet(G, sp);

		output = ouvrirFichierWrite(filename);
		writeGraphe(output, G);
		writeDijkstra(output, G, sp);
		writeAreteVitale(output, vitale);
		fermerFichier(output);

		freeArete(vitale);
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
