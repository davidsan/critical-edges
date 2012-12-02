/**
 * \file packetmod.c
 * \brief Source de Paquet circulaire
 */

#include "packetmod.h"

PaquetMod * creerPaquetMod(Sommet * x) {
	PaquetMod * new = (PaquetMod *) malloc(sizeof(Paquet));
	if (!new) {
		fprintf(stderr, "creerPaquetMod : erreur d'allocation mémoire\n");
	}
	new->x = x;
	new->prec = NULL;
	new->suiv = NULL;
	return new;
}

void freePaquetMod(PaquetMod * p) {
	if (p) {
		free(p->suiv);
		free(p);
	}
}

EnsemblePaquetMod * creerEnsemblePaquetMod(int taille) {
	EnsemblePaquetMod * new = (EnsemblePaquetMod *) malloc(
			sizeof(EnsemblePaquetMod));
	if (!new) {
		fprintf(stderr,
				"creerEnsemblePaquetMod : erreur d'allocation mémoire\n");
	}
	new->taille = taille;
	new->tab = (PaquetMod **) malloc(sizeof(PaquetMod*) * new->taille);
	if (!new->tab) {
		fprintf(stderr,
				"creerEnsemblePaquetMod : erreur d'allocation mémoire\n");
	}
	new->index = 0;
	return new;
}

void freeEnsemblePaquetMod(EnsemblePaquetMod * epm) {
	int i;
	if (epm) {
		for (i = 0; i < epm->taille; ++i) {
			freePaquetMod(epm->tab[i]);
		}
		free(epm->tab);
		free(epm);
	}
}

EnsemblePaquetMod * initialiserEnsemblePaquetMod(int taille) {
	return creerEnsemblePaquetMod(taille);
}

int estVideEnsemblePaquetMod(EnsemblePaquetMod * epm) {
	int i;
	for (i = 0; i < epm->taille; ++i) {
		if (epm->tab[i]) {
			return 0;
		}
	}
	return 1;
}

void ajouterEnsemblePaquetMod(EnsemblePaquetMod * epm, Sommet * x, int l) {
	int pos = l % epm->taille;
	if (!epm || !epm->tab) {
		fprintf(stderr, "ajouterEnsemblePaquetMod : ensemble non initialisé\n");
		return;
	}
	PaquetMod * new = creerPaquetMod(x);
	new->suiv = epm->tab[pos];
	epm->tab[pos] = new;
	if (new->suiv) {
		new->suiv->prec = new;
	}
}

void supprimerEnsemblePaquetMod(EnsemblePaquetMod * epm, Sommet * x, int l) {
	int pos = l % epm->taille;
	if (!epm || !epm->tab) {
		fprintf(stderr,
				"supprimerEnsemblePaquetMod : ensemble non initialisé\n");
		return;
	}
	PaquetMod * current = epm->tab[pos];
	while (current) {
		if (current->x == x) {
			if (current->prec) {
				current->prec->suiv = current->suiv;
			} else {
				epm->tab[pos] = current->suiv;
			}
			if (current->suiv) {
				current->suiv->prec = current->prec;
			}
			free(current);
			return;
		}
		current = current->suiv;
	}
	fprintf(stderr, "supprimerEnsemblePaquetMod : non trouvé\n");

}

void supprimerEnsemblePaquetModMem(EnsemblePaquetMod * epm, Sommet * x, int l) {
	int pos = l % epm->taille;
	if (!epm || !epm->tab) {
		fprintf(stderr,
				"supprimerEnsemblePaquetModMem : ensemble non initialisé\n");
		return;
	}
	PaquetMod * current = epm->tab[pos];
	while (current) {
		if (current->x == x) {
			if (current->prec) {
				current->prec->suiv = current->suiv;
			} else {
				epm->tab[pos] = current->suiv;
			}
			if (current->suiv) {
				current->suiv->prec = current->prec;
			}
			return;
		}
		current = current->suiv;
	}
	fprintf(stderr, "supprimerEnsemblePaquetMod : non trouvé\n");

}
PaquetMod * recupMinEnsemblePaquetMod(EnsemblePaquetMod * epm) {
	int i;
	for (i = 0; i < epm->taille; i++) {
		int k = i + epm->index % epm->taille;
		if (!epm->tab[k]) {
			epm->index = (epm->index + 1) % epm->taille;
			continue;
		}
		PaquetMod * res = epm->tab[k];
		epm->tab[k] = res->suiv;
		if (epm->tab[k]) {
			epm->tab[k]->prec = NULL;
		}
		res->suiv = NULL;
		return res;

	}
	return NULL ;
}

