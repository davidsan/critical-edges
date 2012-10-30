/**
 * \file main.c
 * \brief Programme principal
 */

#include <stdio.h>
#include "reader.h"
#include "graph.h"

int main(int argc, char **argv) {

	FILE * f = NULL;

	Graphe * G = NULL;

	if (argc != 2) {
		fprintf(stderr, "Usage : ./main file.gph\n");
		return 1;
	}

	// fprintf(stdout, "Ouverture du fichier %s\n", argv[1]);
	f = ouvrirFichier(argv[1]);

	G = lectureGraphe(f);

	afficheGraphe(G);

	freeGraphe(G);

	if (f) {
		fermerFichier(f);
	}

	return 0;
}
