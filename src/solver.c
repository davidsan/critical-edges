/**
 * \file solver.c
 * \brief Source de solver
 */
#include "solver.h"

Arete * solveListe(Graphe * G, Arete * sp) {
	Arete * vitale = NULL;
	int coutVitale = 0;
	Arete * current = sp;
	while (current) {
		// désactiver l'arête courante
		switchArete(G, current);
		Dijkstra * D = dijkstraListe(G, G->s);
		Arete * path = extractSP(G, D);
		int cout = calculCout(path);

		if (cout == coutVitale && vitale) {
			vitale = ajouterAreteEnTete(vitale,
					creerArete(current->s1, current->s2, current->poids));
		}
		if (cout > coutVitale) {
			coutVitale = cout;
			freeArete(vitale);
			vitale = creerArete(current->s1, current->s2, current->poids);
		}

		// réactiver l'arête courante
		switchArete(G, current);
		freeArete(path);
		freeDijkstra(D);
		current = current->suivant;
	}
	fprintf(stdout, "Cout engendré par l'arête vitale : %d\n", coutVitale);
	if (!vitale) {
		fprintf(stderr, "Pas d'arête vitale trouvé.\n");
		return NULL ;
	}
	return vitale;
}

Arete * solveTas(Graphe * G, Arete * sp) {
	Arete * vitale = NULL;
	int coutVitale = 0;
	Arete * current = sp;
	while (current) {
		// désactiver l'arête courante
		switchArete(G, current);
		Dijkstra * D = dijkstraTas(G, G->s);
		Arete * path = extractSP(G, D);
		int cout = calculCout(path);

		if (cout == coutVitale && vitale) {
			vitale = ajouterAreteEnTete(vitale,
					creerArete(current->s1, current->s2, current->poids));
		}
		if (cout > coutVitale) {
			coutVitale = cout;
			freeArete(vitale);
			vitale = creerArete(current->s1, current->s2, current->poids);
		}

		// réactiver l'arête courante
		switchArete(G, current);
		freeArete(path);
		freeDijkstra(D);
		current = current->suivant;
	}
	fprintf(stdout, "Cout engendré par l'arête vitale : %d\n", coutVitale);
	if (!vitale) {
		fprintf(stderr, "Pas d'arête vitale trouvé.\n");
		return NULL ;
	}
	return vitale;
}


Arete * solvePaquet(Graphe * G, Arete * sp) {
	Arete * vitale = NULL;
	int coutVitale = 0;
	Arete * current = sp;
	while (current) {
		// désactiver l'arête courante
		switchArete(G, current);
		Dijkstra * D = dijkstraPaquet(G, G->s);
		Arete * path = extractSP(G, D);
		int cout = calculCout(path);

		if (cout == coutVitale && vitale) {
			vitale = ajouterAreteEnTete(vitale,
					creerArete(current->s1, current->s2, current->poids));
		}
		if (cout > coutVitale) {
			coutVitale = cout;
			freeArete(vitale);
			vitale = creerArete(current->s1, current->s2, current->poids);
		}

		// réactiver l'arête courante
		switchArete(G, current);
		freeArete(path);
		freeDijkstra(D);
		current = current->suivant;
	}
	fprintf(stdout, "Cout engendré par l'arête vitale : %d\n", coutVitale);
	if (!vitale) {
		fprintf(stderr, "Pas d'arête vitale trouvé.\n");
		return NULL ;
	}
	return vitale;
}
