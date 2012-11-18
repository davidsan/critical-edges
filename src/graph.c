/**
 * \file graph.c
 * \brief Source de graphe
 */
#include "graph.h"

Sommet * creerSommet(int numero, int x, int y) {
	Sommet * new = (Sommet *) malloc(sizeof(Sommet));
	if (new == NULL ) {
		fprintf(stderr, "creerSommet : erreur d'allocation mémoire\n");
		return NULL ;
	}
	new->numero = numero;
	new->x = x;
	new->y = y;
	new->voisins = NULL;
	return new;
}

Arete * creerArete(Sommet * s1, Sommet * s2, int poids) {
	Arete * new = (Arete *) malloc(sizeof(Arete));
	if (new == NULL ) {
		fprintf(stderr, "creerArete : erreur d'allocation mémoire\n");
		return NULL ;
	}
	new->s1 = s1;
	new->s2 = s2;
	new->poids = poids;
	new->suivant = NULL;
	return new;
}

Graphe * creerGraphe(int nbSommets, int nbAretes) {
	Graphe * new = (Graphe *) malloc(sizeof(Graphe));
	if (new == NULL ) {
		fprintf(stderr, "creerGraphe : erreur d'allocation mémoire\n");
		return NULL ;
	}
	new->nbSommets = nbSommets;
	new->nbAretes = nbAretes;
	new->sommets = (Sommet **) malloc(sizeof(Sommet*) * nbSommets);
	return new;
}

void initGraphe(Graphe * G, int s, int t) {
	if (G == NULL ) {
		fprintf(stderr, "initGraphe : graphe invalide\n");
		return;
	}
	G->s = s;
	G->t = t;
}

void freeSommet(Sommet * s) {
	freeArete(s->voisins);
	free(s);
}

void freeArete(Arete * a) {
	if (a != NULL ) {
		freeArete(a->suivant);
	}
	free(a);
}

void freeGraphe(Graphe * G) {
	int i;
	if (G) {
		for (i = 0; i < G->nbSommets; i++) {
			freeSommet(G->sommets[i]);
		}
		free(G->sommets);
		free(G);
	}
}

Sommet * getSommet(Graphe * G, int n) {
	if (n < 0 || n >= G->nbSommets) {
		fprintf(stderr, "getSommet : numéro de sommet invalide\n");
	}
	return G->sommets[n];
}

Arete * ajouterAreteEnTete(Arete * l, Arete * a) {
	if (a == NULL ) {
		fprintf(stderr, "ajouterAreteEnTete : arête invalide\n");
		return NULL ;
	}
	a->suivant = l;
	return a;
}

Arete * ajouterAreteEnQueue(Arete * l, Arete * a) {
	Arete * tmp = l;
	if (l == NULL ) {
		return a;
	}
	while (tmp->suivant != NULL ) {
		tmp = tmp->suivant;
	}
	tmp->suivant = a;
	return l;
}

void afficheSommet(Sommet * s) {
	if (s == NULL ) {
		fprintf(stderr, "afficheSommet : sommet invalide\n");
		return;
	}
	fprintf(stdout, "%d %d %d\n", s->numero, s->x, s->y);
}

void afficheArete(Arete * a) {
	if (a == NULL ) {
		fprintf(stderr, "afficheArete : arête invalide\n");
		return;
	}
	fprintf(stdout, "%d %d %d\n", a->s1->numero, a->s2->numero, a->poids);
}

void afficheAretes(Arete * l) {
	Arete * tmp = l;
	while (tmp != NULL ) {
		afficheArete(tmp);
		tmp = tmp->suivant;
	}
}

void afficheGraphe(Graphe * G) {
	int i;
	if (G == NULL ) {
		fprintf(stderr, "afficheGraphe : graphe invalide\n");
		return;
	}
	fprintf(stdout, "%d %d\n", G->nbSommets, G->nbAretes);
	fprintf(stdout, "%d %d\n", G->s, G->t);
	for (i = 0; i < G->nbSommets; i++) {
		afficheSommet(G->sommets[i]);
	}
	for (i = 0; i < G->nbSommets; i++) {
		afficheAretes(G->sommets[i]->voisins);
	}
}

Graphe * lectureGrapheInit(FILE * f) {
	char buffer[BUFFER_SIZE];
	char * subStringLeft = NULL;
	char * subStringRight = NULL;
	Graphe * new = NULL;
	if (!readLine(f, buffer)) {
		fprintf(stderr, "lectureGrapheInit : erreur de lecture du fichier");
		return NULL ;
	}
	subStringLeft = strtok(buffer, " ");
	subStringRight = strtok(NULL, "\0");
	int nbSommets = scanInt(subStringLeft);
	int nbAretes = scanInt(subStringRight);

	if (!readLine(f, buffer)) {
		fprintf(stderr, "lectureGrapheInit : erreur de lecture du fichier");
		return NULL ;
	}
	subStringLeft = strtok(buffer, " ");
	subStringRight = strtok(NULL, "\0");
	int s = scanInt(subStringLeft);
	int t = scanInt(subStringRight);
	new = creerGraphe(nbSommets, nbAretes);
	initGraphe(new, s, t);
	return new;
}

Graphe * lectureGraphe(FILE * f) {
	char buffer[BUFFER_SIZE];
	char * subStringLeft = NULL;
	char * subStringCenter = NULL;
	char * subStringRight = NULL;
	Graphe * G = NULL;
	int i = 0;
	G = lectureGrapheInit(f);
	for (i = 0; i < G->nbSommets; i++) {
		if (!readLine(f, buffer)) {
			fprintf(stderr, "lectureGraphe : erreur de lecture du fichier");
			return NULL ;
		}
		subStringLeft = strtok(buffer, " ");
		subStringCenter = strtok(NULL, " ");
		subStringRight = strtok(NULL, "\0");
		G->sommets[i] = creerSommet(scanInt(subStringLeft),
				scanInt(subStringCenter), scanInt(subStringRight));
	}
	for (i = 0; i < G->nbAretes; i++) {
		if (!readLine(f, buffer)) {
			fprintf(stderr, "lectureGraphe : erreur de lecture du fichier");
			return NULL ;
		}
		subStringLeft = strtok(buffer, " ");
		subStringCenter = strtok(NULL, " ");
		subStringRight = strtok(NULL, "\0");
		int sommetA = scanInt(subStringLeft);
		int sommetB = scanInt(subStringCenter);
		int poids = scanInt(subStringRight);
		G->sommets[sommetA]->voisins = ajouterAreteEnQueue(
				G->sommets[sommetA]->voisins,
				creerArete(G->sommets[sommetA], G->sommets[sommetB], poids));
		G->sommets[sommetB]->voisins = ajouterAreteEnQueue(
				G->sommets[sommetB]->voisins,
				creerArete(G->sommets[sommetB], G->sommets[sommetA], poids));
	}
	return G;
}

void switchArete(Graphe * G, Arete * A) {
	Arete * current = NULL;
	current = G->sommets[A->s1->numero]->voisins;
	while (current) {
		if (current->s2 == A->s2) {
			current->poids = -current->poids;
			break;
		}
		current = current->suivant;
	}
	current = G->sommets[A->s2->numero]->voisins;
	while (current) {
		if (current->s1 == A->s1) {
			current->poids = -current->poids;
			break;
		}
		current = current->suivant;
	}
}
