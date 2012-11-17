/**
 * \file dijkstra.h
 * \brief En-tête de dijkstra
 */

#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "liste.h"

/**
 * @struct Dijkstra
 * Structure d'un résultat de l'algorithme Dijkstra
 */
typedef struct dijkstra {
	int size; /*!< Taille des tableaux */
	int * dist; /*!< Tableau des distances */
	Arete ** pred; /*!< Tableau des predécesseurs */
} Dijkstra;

/**
 * Fonction d'allocation de Dijkstra
 * @param size Taille des tableaux
 * @return Adresse vers l'instance de type Dijkstra allouée
 */
Dijkstra* creerDijkstra(int size);

/**
 * Fonction de désallocation de Dijkstra
 * @param d Adresse vers une instance de type Dijkstra à désallouer
 */
void freeDijkstra(Dijkstra* d);

/**
 * Fonction Dijkstra utilisant une liste en tant que bordure
 * @param G Adresse vers un graphe
 * @param r Numéro de la racine
 * @return Adresse vers une instance de type Dijkstra
 */
Dijkstra * dijkstraListe(Graphe * G, int r);

/**
 * Fonction d'extraction du plus court chemin
 * @param G
 * @param D
 * @return
 */
Arete * extractSP(Graphe * G, Dijkstra *D);

#endif /* DIJKSTRA_H_ */
