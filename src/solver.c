/**
 * \file solver.c
 * \brief Source de solver
 */
#include "solver.h"

Arete * solveListe(Graphe * G, Arete * sp) {
	Arete * vitale = sp;
	int coutVitale = 0;
	Arete * current = sp;
	while (current) {
		// désactiver l'arête courante
		switchArete(G, current);
		Dijkstra * D = dijkstraListe(G, G->s);
		Arete * path = extractSP(G, D);
		int cout = calculCout(path);
		if (cout > coutVitale) {
			coutVitale = cout;
			vitale = current;
		}
		// réactiver l'arête courante
		switchArete(G, current);
		freeArete(path);
		freeDijkstra(D);
		current = current->suivant;
	}
	fprintf(stdout, "Cout engendré par l'arête vitale : %d\n", coutVitale);
	return vitale;
}
