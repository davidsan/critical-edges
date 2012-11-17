/**
 * \file liste.h
 * \brief En-tête de scanner
 */
#ifndef LISTE_H_
#define LISTE_H_

#include "graph.h"

/**
 * @struct Element
 * Structure d'un élément
 */
typedef struct element {
	Sommet * x; /*!< Sommet */
	int l; /*!< Longueur minimale d'une chaîne d'un sommet déterminé vers le sommet x */
	struct element * next; /*!< Adresse vers l'élément suivant */
} Element;

/**
 * @struct Liste
 * Structure d'une liste
 */
typedef struct liste {
	Element * hd; /*!< Adresse vers la tête de la liste */
} Liste;

/**
 * @brief Fonction de création d'un élément
 * @param x Sommet
 * @param l Longueur minimale d'une chaine d'un sommet déterminé vers le sommet x
 * @return Element crée
 */
Element * creerElement(Sommet * x, int l);
/**
 * @brief Fonction de création d'une liste
 * @return Liste crée
 */
Liste * creerListe();
/**
 * @brief Fonction de libération mémoire des éléments en cascade
 * @param e Element de départ
 */
void freeElement(Element * e);
/**
 * @brief Fonction de libération mémoire d'une liste
 * @param list Liste à détruire
 */
void freeListe(Liste * list);


/**
 * @brief Fonction d'affichage textuel de la liste
 * @param list Liste à afficher
 */
void display(Liste * list);


/* primitives required */
/**
 * @brief Fonction d'initialisation d'une liste
 * @return Liste initialisée
 */
Liste * initialiser();
/**
 * Fonction qui teste si la liste est vide
 * @param list Liste
 * @return 1 si la liste est vide, sinon 0
 */
int est_vide(Liste * list);
/**
 * Fonction d'ajout d'un élément à la liste
 * @param list Liste
 * @param x Sommet à ajouter
 * @param l Longueur associé
 */
void ajouter(Liste * list, Sommet * x, int l);
/**
 * Fonction de suppression d'un élément contenant un sommet précisé
 * @param list Liste
 * @param x Sommet à supprimer de la liste
 */
void supprimer(Liste * list, Sommet * x);
/**
 * @brief Fonction de récupération du minimum dans la liste
 * @param list Liste
 * @return Adresse vers l'élément minimum
 */
Element * recup_min(Liste * list);

#endif /* LISTE_H_ */
