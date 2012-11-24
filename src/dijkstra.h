/**
 * \file dijkstra.h
 * \brief En-tête de dijkstra
 */

#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "list.h"
#include "heap.h"
#include "packet.h"

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
 * @brief Fonction d'allocation de Dijkstra
 * @param size Taille des tableaux
 * @return Adresse vers l'instance de type Dijkstra allouée
 */
Dijkstra* creerDijkstra(int size);

/**
 * @brief Fonction de désallocation de Dijkstra
 * @param d Adresse vers une instance de type Dijkstra à désallouer
 */
void freeDijkstra(Dijkstra* d);

/**
 * @brief Fonction Dijkstra utilisant une liste en tant que bordure
 * @param G Adresse vers un graphe
 * @param r Numéro de la racine
 * @return Adresse vers une instance de type Dijkstra
 */
Dijkstra * dijkstraListe(Graphe * G, int r);

/**
 * @brief Fonction d'extraction du plus court chemin
 * @param G Adresse vers un graphe
 * @param D Adresse vers une instance de type Dijkstra
 * @return Liste d'arête composé du plus court chemin entre s et t (défini dans G)
 */
Arete * extractSP(Graphe * G, Dijkstra *D);


/**
 * @brief Fonction Dijkstra utilisant un tas en tant que bordure
 * @param G Adresse vers un graphe
 * @param r Numéro de la racine
 * @return Adresse vers une instance de type Dijkstra
 */
Dijkstra * dijkstraTas(Graphe * G, int r);

/**
 * @brief Fonction Dijkstra utilisant un ensemble de paquets en tant que bordure
 * @param G Adresse vers un graphe
 * @param r Numéro de la racine
 * @return Adresse vers une instance de type Dijkstra
 */
Dijkstra * dijkstraPaquet(Graphe * G, int r);

#endif /* DIJKSTRA_H_ */
