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
	fprintf(stdout, "Cost generated by the most critical edge : %d\n",
			coutVitale);
	if (!vitale) {
		fprintf(stdout, "Most critical edge not found.\n");
		fprintf(stdout,
				"This graph may not contain any critical edge for this shortest path.\n");
		return NULL ;
	}
	fprintf(stdout, "The most critical edge is (%d; %d)\n",
			vitale->s1->numero, vitale->s2->numero);
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
	fprintf(stdout, "Cost generated by the most critical edge : %d\n",
			coutVitale);
	if (!vitale) {
		fprintf(stdout, "Most critical edge not found.\n");
		fprintf(stdout,
				"This graph may not contain any critical edge for this shortest path.\n");
		return NULL ;
	}
	fprintf(stdout, "The most critical edge is (%d; %d)\n",
			vitale->s1->numero, vitale->s2->numero);
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
	fprintf(stdout, "Cost generated by the most critical edge : %d\n",
			coutVitale);
	if (!vitale) {
		fprintf(stdout, "Most critical edge not found.\n");
		fprintf(stdout,
				"This graph may not contain any critical edge for this shortest path.\n");
		return NULL ;
	}
	fprintf(stdout, "The most critical edge is (%d; %d)\n",
			vitale->s1->numero, vitale->s2->numero);
	return vitale;
}

Arete * solvePaquetMod(Graphe * G, Arete * sp) {
	Arete * vitale = NULL;
	int coutVitale = 0;
	Arete * current = sp;
	while (current) {
		// désactiver l'arête courante
		switchArete(G, current);
		Dijkstra * D = dijkstraPaquetMod(G, G->s);
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
	fprintf(stdout, "Cost generated by the most critical edge : %d\n",
			coutVitale);
	if (!vitale) {
		fprintf(stdout, "Most critical edge not found.\n");
		fprintf(stdout,
				"This graph may not contain any critical edge for this shortest path.\n");
		return NULL ;
	}
	fprintf(stdout, "The most critical edge is (%d; %d)\n",
			vitale->s1->numero, vitale->s2->numero);
	return vitale;
}
