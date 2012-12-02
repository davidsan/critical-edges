/**
 * \file solver.h
 * \brief En-tête de solver
 */
#ifndef SOLVER_H_
#define SOLVER_H_

#include <limits.h>
#include "graph.h"
#include "dijkstra.h"

/**
 * @brief Fonction qui recherche les arêtes vitales d'un graphe et d'un chemin associé en utilisant une liste comme bordure
 * @param G Adresse d'un graphe
 * @param sp Liste d'arêtes représentant un chemin
 * @return Liste d'arêtes vitales
 */
Arete * solveListe(Graphe * G, Arete * sp);

/**
 * @brief Fonction qui recherche les arêtes vitales d'un graphe et d'un chemin associé en utilisant un tas comme bordure
 * @param G Adresse d'un graphe
 * @param sp Liste d'arêtes représentant un chemin
 * @return Liste d'arêtes vitales
 */
Arete * solveTas(Graphe * G, Arete * sp);

/**
 * @brief Fonction qui recherche les arêtes vitales d'un graphe et d'un chemin associé en utilisant un ensemble de paquet comme bordure
 * @param G Adresse d'un graphe
 * @param sp Liste d'arêtes représentant un chemin
 * @return Liste d'arêtes vitales
 */
Arete * solvePaquet(Graphe * G, Arete * sp);

/**
 * @brief Fonction qui recherche les arêtes vitales d'un graphe et d'un chemin associé en utilisant un ensemble de paquet optimisé comme bordure
 * @param G Adresse d'un graphe
 * @param sp Liste d'arêtes représentant un chemin
 * @return Liste d'arêtes vitales
 */
Arete * solvePaquetMod(Graphe * G, Arete * sp);

#endif /* SOLVER_H_ */
