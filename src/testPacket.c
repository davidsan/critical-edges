/**
 * \file testEnsemblePaquet.c
 * \brief Programme de test de la structure Paquet
 */
#include "packet.h"

int main(int argc, char **argv) {
	EnsemblePaquet * ens = initialiserEnsemblePaquet(5);
	Sommet * s1 = creerSommet(1, 1, 1);
	Sommet * s2 = creerSommet(2, 2, 2);
	Sommet * s3 = creerSommet(3, 3, 3);
	Sommet * s4 = creerSommet(4, 4, 4);
	Sommet * s5 = creerSommet(5, 5, 5);

	ajouterEnsemblePaquet(ens, s1, 1);
	ajouterEnsemblePaquet(ens, s1, 1);
	ajouterEnsemblePaquet(ens, s1, 1);
	ajouterEnsemblePaquet(ens, s2, 2);
	ajouterEnsemblePaquet(ens, s3, 3);
	ajouterEnsemblePaquet(ens, s4, 4);
	ajouterEnsemblePaquet(ens, s5, 5);

	afficherEnsemblePaquet(ens);
	fprintf(stderr, "recup min : %d\n", recupMinEnsemblePaquet(ens)->x->numero);
	afficherEnsemblePaquet(ens);

	supprimerEnsemblePaquet(ens, s3, 3);
	afficherEnsemblePaquet(ens);
	return 0;
}
