/**
 * @mainpage Projet Réseau
 * @section intro_sec Introduction
 * On considère un graphe non-orienté connexe G=(S,A) valué par une fonction c qui associe à chaque arête un entier positif représentant son coût, ainsi que deux sommets distincts s et t. On note par n le nombre de sommets de G et m son nombre d'arêtes. Une arête est dite critique si sa suppression du graphe entraîne une dégradation (stricte) de la longueur (définie par la somme des coûts des arêtes de la chaîne) de la plus courte chaîne entre s et t. L'arête critique qui entraine la plus forte dégradation de la longueur de la plus courte chaîne entre s et t sera dite vitale. Nous nous intéressons ici au problème de la recherche d'une arête vitale dans un graphe G.
 *
 * Le problème de la recherche d'une arête vitale dans un graphe trouve une application naturelle dans l'exploitation des réseaux de télécommunications. En effet, un réseau de télécommunications (téléphone, internet,…) peut être décrit comme un graphe où les sommets sont des clients ou des concentrateurs (hubs), et les arêtes sont les câbles liant des clients ou des concentrateurs. Chaque câble possède un débit maximal qui peut être vu comme un temps de transfert d'informations : ce temps constitue le coût d'une arête. L'existence d'une arête-câble vitale dans un réseau entre deux utilisateurs (et surtout entre deux concentrateurs) est une cause de mauvaise qualité de communication du réseau.
 *
 * En effet, les algorithmes de routage des données dans le réseau auront tendance à sur-utiliser ce câble qui sera vite saturé, provoquant alors un ralentissement des communications. D'autre part, en cas de panne de cette liaison, les communications sont immédiatement dégradées : en effet, le re-routage des informations va devoir utiliser une chaîne plus lente pour router la même demande entre deux clients.
 *
 * Le but de ce projet est d'étudier plusieurs versions d'un algorithme permettant de déterminer une arête vitale dans un graphe non-orienté, si elle existe. Une analyse théorique et expérimentale devra être menée pour définir et vérifier expérimentalement l'efficacité des implémentations proposées.
 *
 * @section install_sec Installation
 *
 * $ make
 *
 * @subsection running Exécution
 *
 * - $ ./main
 * - $ ./convertPostscript <gph-files>
 * - $ ./convertPostscriptDijkstra <datastruct> <gph-files>
 * - $ ./convertPostscriptCritical <datastruct> <gph-files>
 * - $ ./convertTimer <datastruct> <gph-files>
 *
 * @section author Auteur
 * David San, Kamalraj Muruganathan
 */

/**
 * \file main.c
 * \brief Programme de lecture d'un graphe
 * \author David San
 *
 *
 */

#include <stdio.h>
#include "reader.h"
#include "graph.h"

int main(int argc, char **argv) {

	FILE * f = NULL;

	Graphe * G = NULL;

	if (argc != 2) {
		fprintf(stderr, "Usage : ./main file.gph\n");
		return 1;
	}

	// fprintf(stdout, "Ouverture du fichier %s\n", argv[1]);
	f = ouvrirFichierRead(argv[1]);

	G = lectureGraphe(f);

	afficheGraphe(G);

	freeGraphe(G);

	if (f) {
		fermerFichier(f);
	}

	return 0;
}
