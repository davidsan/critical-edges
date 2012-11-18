/**
 * \file dijkstra.h
 * \brief Source de dijkstra
 */

#include "dijkstra.h"

Dijkstra* creerDijkstra(int size) {
	Dijkstra * new = (Dijkstra*) malloc(sizeof(Dijkstra));
	new->size = size;
	new->dist = (int*) malloc(sizeof(int) * size);
	new->pred = (Arete**) malloc(sizeof(Arete*) * size);
	return new;
}

void freeDijkstra(Dijkstra* d) {
	if (d) {
		free(d->dist);
		free(d->pred);
		free(d);
	}
}

Dijkstra * dijkstraListe(Graphe * G, int r) {
	Dijkstra * res = creerDijkstra(G->nbSommets);
	/* aliases */
	int * dist = res->dist;
	Arete ** pred = res->pred;
	int i;
	for (i = 0; i < G->nbSommets; ++i) {
		res->pred[i] = NULL;
	}
	Liste * l = initialiserListe();
	ajouterElementListe(l, G->sommets[r], 0);
	dist[r] = 0;
	pred[r] = NULL;

	int testcpt = 0;
	while (!estVideListe(l)) {
		Element * min = recupMinListe(l);
		Arete * voisin = min->x->voisins;
		int x = min->x->numero;
		freeElement(min);
		while (voisin) {
			int y = voisin->s2->numero;
			if (voisin->poids < 0) {
				/* Les arêtes de poids négatives sont ignorés */
				voisin = voisin->suivant;
				continue;
			}
			if (pred[y] == NULL ) {
				testcpt++;
				dist[y] = dist[x] + voisin->poids;
				pred[y] = voisin;
				ajouterElementListe(l, G->sommets[y], dist[y]);
			} else {
				if (dist[y] > dist[x] + voisin->poids) {
					dist[y] = dist[x] + voisin->poids;
					pred[y] = voisin;
					supprimerElementListe(l, G->sommets[y]);
					ajouterElementListe(l, G->sommets[y], dist[y]);
				}
			}
			voisin = voisin->suivant;
		}
	}
	freeListe(l);
	// printf("Dijkstra done.\n");
	return res;
}

Arete * extractSP(Graphe * G, Dijkstra *D) {
	Arete * res = NULL;
	Arete * cursor = D->pred[G->t];
	//	printf("%d to %d\n", G->t, G->s);
	while (cursor) {
		if (cursor->s2->numero == G->s) {
			break;
		}
		//	printf("%d --> ", cursor->s2->numero);
		res = ajouterAreteEnTete(res,
				creerArete(cursor->s1, cursor->s2, cursor->poids));
		cursor = D->pred[cursor->s1->numero];
	}
	// printf("\n");
	/*
	 if (!res) {
	 fprintf(stderr, "Pas de chemin trouvé.\n");
	 }
	 */
	return res;
}

int calculCout(Arete * l) {
	Arete * current = l;
	int cout = 0;
	while (current) {
		cout += current->poids;
		current = current->suivant;
	}
	return cout;
}
