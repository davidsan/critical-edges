/**
 * \file fichier.h
 * \brief En-tête de graphe
 */
#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reader.h" /* Pour la constante BUFFER_SIZE */
#include "scanner.h"

/**
 * @struct sommet
 * Structure d'un sommet
 */
typedef struct sommet {
	int numero; /*!< Numéro du sommet */
	int x; /*!< Coordonnée x du sommet */
	int y; /*!< Coordonnée y du sommet */
	struct arete * voisins;
} Sommet;

/**
 * @struct arete
 * Structure d'une arête
 */
typedef struct arete {
	struct sommet * s1; /*!< Sommet s1 */
	struct sommet * s2; /*!< Sommet s2 */
	int poids; /*!< Poids de l'arete (s1, s2) */
	struct arete * suivant; /*!< Pointeur sur l'arete suivante */
} Arete;

/**
 * @struct graphe
 * Structure d'un graphe
 */
typedef struct graphe {
	int nbSommets; /*!< Nombre de sommets */
	int nbAretes; /*!< Nombre d'aretes */
	int s; /*!< Numéro du sommet de départ */
	int t; /*!< Numéro du sommet d'arrivée */
	struct sommet ** sommets; /*!< Tableau de sommets */
} Graphe;

/**
 * @brief Fonction de création d'une arête
 * @param s1 Premier sommet de l'arête
 * @param s2 Deuxième sommet de l'arête
 * @param poids Poids de l'arête
 * @return Adresse de la nouvelle instance allouée de type Arete
 */
Arete * creerArete(Sommet * s1, Sommet * s2, int poids);

/**
 * @brief Fonction de création d'un sommet
 * @param x Ordonnée
 * @param y Abscisse
 * @param numero Numéro
 * @return Adresse de la nouvelle instance allouée de type Sommet
 */
Sommet * creerSommet(int x, int y, int numero);

/**
 * @brief Fonction de création d'un graphe
 * @param nbSommets Nombre de sommets du graphe
 * @param nbAretes Nombre d'arêtes du graphe
 * @return Adresse de la nouvelle instance allouée de type Graphe
 */
Graphe * creerGraphe(int nbSommets, int nbAretes);

/**
 * @brief Fonction d'initialisation des sommets s et t du graphe
 * @param G Graphe à initialiser
 * @param s Sommet s
 * @param t Sommet t
 */
void initGraphe(Graphe * G, int s, int t);

/**
 * @brief Fonction de désallocation d'une arête
 * @param a Arete à désallouer
 */
void freeArete(Arete * a);

/**
 * @brief Fonction de désallocation d'un sommet
 * @param s Sommet à désallouer
 */
void freeSommet(Sommet * s);

/**
 * @brief Fonction de désallocation d'un graphe
 * @param G Graphe à désallouer
 */
void freeGraphe(Graphe * G);

/**
 * @brief Fonction de récupération de l'adresse d'un sommet à partir de son numéro
 * @param G Graphe dans lequel le sommet est situé
 * @param n Numéro du sommet à récupérer
 * @return Adresse du sommet recherché
 */
Sommet * getSommet(Graphe * G, int n);

/**
 * @brief Fonction d'ajout en tête de la liste des arêtes
 * @param l Adresse vers le premier élément de la liste des arêtes
 * @param a Adresse vers une arête à ajouter
 * @return Adresse vers le premier élément de la liste une fois l'élément ajouté
 */
Arete * ajouterAreteEnTete(Arete * l, Arete * a);

/**
 * @brief Fonction d'ajout en queue de la liste des arêtes
 * @param l Adresse vers le premier élément de la liste des arêtes
 * @param a Adresse vers une arête à ajouter
 * @return Adresse vers le premier élément de la liste une fois l'élément ajouté
 */
Arete * ajouterAreteEnQueue(Arete * l, Arete * a);

/**
 * @brief Fonction d'affichage d'un sommet
 * @param s Adresse du sommet à afficher
 */
void afficheSommet(Sommet * s);

/**
 * @brief Fonction d'affichage d'une arête
 * @param a Adresse de l'arête à afficher
 */
void afficheArete(Arete * a);

/**
 * @brief Fonction d'affichage de la liste des arêtes
 * @param l Adresse vers le premier élément de la liste des arêtes
 */
void afficheAretes(Arete * l);

/**
 * @brief Fonction d'affichage d'un graphe
 * @param G Adresse vers le graphe à afficher
 */
void afficheGraphe(Graphe * G);

/**
 * @brief Fonction de lecture d'un graphe à partir d'un flux (initialisation uniquement)
 * @param f Adresse du flux de lecture
 * @return Adresse du graphe lu
 */
Graphe * lectureGrapheInit(FILE * f);

/**
 * @brief Fonction de lecture d'un graphe à partir d'un flux
 * @param f Adresse du flux de lecture
 * @return Adresse du graphe lu
 */
Graphe * lectureGraphe(FILE * f);

#endif
