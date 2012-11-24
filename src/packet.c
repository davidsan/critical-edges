/**
 * \file packet.c
 * \brief Source de Paquet
 */

#include "packet.h"

Paquet * creerPaquet(Sommet * x) {
	Paquet * p = (Paquet *) malloc(sizeof(Paquet));
	if (!p) {
		fprintf(stderr, "creerPaquet : erreur d'allocation mémoire\n");
		return NULL ;
	}
	p->x = x;
	p->prec = NULL;
	p->suiv = NULL;
	return p;
}

EnsemblePaquet * creerEnsemblePaquet(int taille) {
	int i;
	EnsemblePaquet * ens = (EnsemblePaquet*) malloc(sizeof(EnsemblePaquet));
	if (!ens) {
		fprintf(stderr, "creerEnsemblePaquet : erreur d'allocation mémoire\n");
		return NULL ;
	}
	ens->taille = taille;
	ens->tab = (Paquet**) malloc(sizeof(Paquet*) * ens->taille);
	if (!ens->tab) {
		fprintf(stderr, "creerEnsemblePaquet : erreur d'allocation mémoire\n");
		free(ens);
		return NULL ;
	}
	for (i = 0; i < ens->taille; i++) {
		ens->tab[i] = NULL;
	}
	return ens;
}

void freePaquet(Paquet * p) {
	if (p) {
		freePaquet(p->suiv);
		free(p);
	}
}

void freeEnsemblePaquet(EnsemblePaquet * ens) {
	int i;
	for (i = 0; i < ens->taille; i++) {
		freePaquet(ens->tab[i]);
	}
	free(ens->tab);
	free(ens);
}

void afficherPaquet(Paquet * p) {
	if (p == NULL ) {
		fprintf(stdout, "vide\n");
		return;
	}
	Paquet * current = p;
	while (current) {
		fprintf(stdout, "%d ", current->x->numero);
		current = current->suiv;
	}
	fprintf(stdout, "\n");
}

void afficherEnsemblePaquet(EnsemblePaquet * ens) {
	int i;
	if (ens == NULL ) {
		fprintf(stderr, "afficheEnsemblePaquet : ensemble paquet invalide\n");
		return;
	}
	fprintf(stdout, "[ensemblePaquet : taille = %d]\n", ens->taille);
	for (i = 0; i < ens->taille; i++) {
		fprintf(stdout, " [paquet %d] ", i);
		afficherPaquet(ens->tab[i]);
	}
}

EnsemblePaquet * initialiserEnsemblePaquet(int taille) {
	return creerEnsemblePaquet(taille);
}

int estVideEnsemblePaquet(EnsemblePaquet * ens) {
	int i;
	if (!ens || !ens->tab) {
		fprintf(stderr,
				"estVideEnsemblePaquet : erreur ensemblePaquet non initialisé\n");
		return -1;
	}
	for (i = 0; i < ens->taille; i++) {
		if (ens->tab[i] != NULL ) {
			return 0;
		}
	}
	return 1;
}

void ajouterEnsemblePaquet(EnsemblePaquet * ens, Sommet * x, int l) {
	if (!ens || !ens->tab) {
		fprintf(stderr,
				"ajouterEnsemblePaquet : erreur ensemblePaquet non initialisé\n");
		return;
	}
	Paquet * p = creerPaquet(x);
	if (ens->tab[l]) {
		ens->tab[l]->prec = p;
	}
	p->suiv = ens->tab[l];
	ens->tab[l] = p;
}

void supprimerEnsemblePaquet(EnsemblePaquet * ens, Sommet * x, int l) {
	if (!ens || !ens->tab) {
		fprintf(stderr,
				"supprimerEnsemblePaquet : erreur ensemblePaquet non initialisé\n");
		return;
	}
	Paquet * current = ens->tab[l];
	while (current) {
		if (current->x == x) {
			if (current->prec) {
				current->prec->suiv = current->suiv;
			} else {
				ens->tab[l] = current->suiv;
			}
			if (current->suiv) {
				current->suiv->prec = current->prec;
			}
			free(current);
			return;
		}
		current = current->suiv;
	}
	fprintf(stderr, "supprimerEnsemblePaquet : non trouvé\n");
}

void supprimerEnsemblePaquetMem(EnsemblePaquet * ens, Sommet * x, int l) {
	if (!ens || !ens->tab) {
		fprintf(stderr,
				"supprimerEnsemblePaquet : erreur ensemblePaquet non initialisé\n");
		return;
	}
	Paquet * current = ens->tab[l];
	while (current) {
		if (current->x == x) {
			current->suiv = current->prec;
			if (ens->tab[l] == current) {
				ens->tab[l] = current->suiv;
			}
			return;
		}
		current = current->suiv;
	}
}

Paquet * recupMinEnsemblePaquet(EnsemblePaquet * ens) {
	int i;
	if (estVideEnsemblePaquet(ens)) {
		fprintf(stderr,
				"recupMinEnsemblePaquet : erreur ensemblePaquet vide\n");
		return NULL ;
	}
	for (i = 0; i < ens->taille; i++) {
		if (!ens->tab[i]) {
			continue;
		}
		Paquet * res = ens->tab[i];
		ens->tab[i] = res->suiv;
		if (ens->tab[i]) {
			ens->tab[i]->prec = NULL;
		}
		res->suiv = NULL;
		return res;

	}
	return NULL ;
}
