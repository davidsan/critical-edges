/**
 * \file testListe.c
 * \brief Programme de test des listes
 */
#include <stdio.h>
#include "liste.h"

int main(int argc, char **argv) {
	Liste * l1 = initialiser();

	Sommet * s1 = creerSommet(0, 0, 0);
	Sommet * s2 = creerSommet(1, 1, 1);
	Sommet * s3 = creerSommet(2, 2, 2);
	Sommet * s4 = creerSommet(3, 3, 3);
	Sommet * s5 = creerSommet(4, 4, 4);

	ajouter(l1, s2, 2);
	ajouter(l1, s1, 1);
	ajouter(l1, s4, 4);
	ajouter(l1, s3, 3);
	ajouter(l1, s5, 5);

	display(l1);

	return 0;
}
