/**
 * \file packet.h
 * \brief En-tête de Paquet
 */
#ifndef PACKET_H_
#define PACKET_H_

#include "graph.h"

typedef struct paquet {
	Sommet * x;
	struct paquet * prec;
	struct paquet * suiv;
} Paquet;

typedef struct ensemblePaquet {
	int taille;
	Paquet ** tab;
} EnsemblePaquet;

Paquet * creerPaquet(Sommet * x);
EnsemblePaquet * creerEnsemblePaquet(int taille);
void freePaquet(Paquet * p);
void freeEnsemblePaquet(EnsemblePaquet * ens);
void afficherPaquet(Paquet * p);
void afficherEnsemblePaquet(EnsemblePaquet * ens);

/* primitives required */
EnsemblePaquet * initialiserEnsemblePaquet(int taille);
int estVideEnsemblePaquet(EnsemblePaquet * ens);
void ajouterEnsemblePaquet(EnsemblePaquet * ens, Sommet * x, int l);
void supprimerEnsemblePaquet(EnsemblePaquet * ens, Sommet * x, int l);
void supprimerEnsemblePaquetMem(EnsemblePaquet * ens, Sommet * x, int l);
Paquet * recupMinEnsemblePaquet(EnsemblePaquet * ens);

#endif
