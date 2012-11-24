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

	while (!estVideListe(l)) {
		Element * min = recupMinListe(l);
		Arete * voisin = min->x->voisins;
		int x = min->x->numero;
		freeElement(min);
		while (voisin) {
			int y = voisin->s2->numero;
			if (voisin->poids < 0) {
				/* Les arêtes de poids négatifs sont ignorées */
				voisin = voisin->suivant;
				continue;
			}
			if (pred[y] == NULL ) {
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
	return res;
}

Arete * extractSP(Graphe * G, Dijkstra *D) {
	Arete * res = NULL;
	Arete * cursor = D->pred[G->t];
	while (cursor) {
		if (cursor->s2->numero == G->s) {
			break;
		}
		res = ajouterAreteEnTete(res,
				creerArete(cursor->s1, cursor->s2, cursor->poids));
		cursor = D->pred[cursor->s1->numero];
	}
	return res;
}

Dijkstra * dijkstraTas(Graphe * G, int r) {
	Dijkstra * res = creerDijkstra(G->nbSommets);
	/* aliases */
	int * dist = res->dist;
	Arete ** pred = res->pred;
	int i;
	for (i = 0; i < G->nbSommets; ++i) {
		res->pred[i] = NULL;
	}
	Heap * h = initialiserTas(G->nbSommets);
	ajouterElementTas(h, G->sommets[r], 0);
	dist[r] = 0;
	pred[r] = NULL;

	while (!estVideTas(h)) {
		HeapNode * min = recupMinTas(h);
		Arete * voisin = min->x->voisins;
		int x = min->x->numero;
		freeHeapNode(min);
		while (voisin) {
			int y = voisin->s2->numero;
			if (voisin->poids < 0) {
				voisin = voisin->suivant;
				continue;
			}
			if (pred[y] == NULL ) {
				dist[y] = dist[x] + voisin->poids;
				pred[y] = voisin;

				ajouterElementTas(h, G->sommets[y], dist[y]);
			} else {
				if (dist[y] > dist[x] + voisin->poids) {
					dist[y] = dist[x] + voisin->poids;
					pred[y] = voisin;
					supprimerElementTas(h, G->sommets[y]);
					ajouterElementTas(h, G->sommets[y], dist[y]);
				}
			}
			voisin = voisin->suivant;
		}
	}
	freeHeap(h);
	return res;
}

Dijkstra * dijkstraPaquet(Graphe * G, int r) {
	Dijkstra * res = creerDijkstra(G->nbSommets);
	/* aliases */
	int * dist = res->dist;
	Arete ** pred = res->pred;
	int coutMax = 0;
	Arete * tmp;
	int i;
	for (i = 0; i < G->nbSommets; ++i) {
		res->pred[i] = NULL;
		tmp = G->sommets[i]->voisins;
		while (tmp) {
			if (tmp->poids > coutMax) {
				coutMax = tmp->poids;
			}
			tmp = tmp->suivant;
		}
	}
	EnsemblePaquet * ens = initialiserEnsemblePaquet(coutMax * G->nbSommets);
	ajouterEnsemblePaquet(ens, G->sommets[r], 0);
	dist[r] = 0;
	pred[r] = NULL;

	while (!estVideEnsemblePaquet(ens)) {
		Paquet * min = recupMinEnsemblePaquet(ens);
		Arete * voisin = min->x->voisins;
		int x = min->x->numero;
		free(min);
		while (voisin) {
			int y = voisin->s2->numero;
			if (voisin->poids < 0) {
				voisin = voisin->suivant;
				continue;
			}
			if (pred[y] == NULL ) {
				dist[y] = dist[x] + voisin->poids;
				pred[y] = voisin;
				ajouterEnsemblePaquet(ens, G->sommets[y], dist[y]);
			} else {
				int oldDist = dist[y];
				if (dist[y] > dist[x] + voisin->poids) {
					dist[y] = dist[x] + voisin->poids;
					pred[y] = voisin;
					supprimerEnsemblePaquet(ens, G->sommets[y], oldDist);
					ajouterEnsemblePaquet(ens, G->sommets[y], dist[y]);
				}
			}
			voisin = voisin->suivant;
		}
	}
	freeEnsemblePaquet(ens);
	return res;
}
