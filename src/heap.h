/**
 * \file heap.h
 * \brief En-tête du tas
 */
#ifndef HEAP_H_
#define HEAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "graph.h"

/**
 * @struct heapNode
 * Noeud de tas
 */
typedef struct heapNode {
	Sommet * x; /*!< Sommet */
	int l; /*!< Longueur minimale d'une chaîne d'un sommet déterminé vers le sommet x */
} HeapNode;

/**
 * @struct heap
 * Tas
 */
typedef struct heap {
	HeapNode **tab; /*!< Tas */
	int *pos; /*!< Tableau qui mémorise la position de chaque sommet dans le tas */
	int size; /*!< Taille */
	int count; /*!< Nombre d'éléments */
} Heap;

/**
 * @brief Fonction de création d'un noeud de tas
 * @param x Sommet
 * @param l Longueur minimale d'une chaîne d'un sommet déterminé vers le sommet x
 * @return Pointeur vers une nouvelle instance allouée de type HeapNode.
 */
HeapNode *createHeapNode(Sommet * x, int l);
/**
 * @brief Fonction de destruction d'un noeud de tas
 * @param n Pointeur vers le noeud à détruire
 */
void freeHeapNode(HeapNode * n);

/**
 * @brief Fonction de création d'un tas
 * @param size Taille du tas à créer
 * @return Pointeur vers une nouvelle instance allouée de type Heap.
 */
Heap *createHeap(int size);
/**
 * @brief Fonction de destruction d'un tas
 * @param h Pointeur vers le tas à détruire
 */
void freeHeap(Heap * h);
/**
 * @brief Fonction qui vérifie si un nombre est une puissance de 2
 * @param x Entier non signée à vérifier
 * @return 1 si l'entier est une puissance de 2, sinon 0.
 */
int isPowerOfTwo(unsigned int x);
/**
 * @brief Fonction d'affichage d'un tas
 * @param h Pointeur vers le tas à afficher
 */
void displayHeap(Heap * h);
/**
 * @brief Fonction d'affichage d'un tas
 * @param h Pointeur vers le tas à afficher
 */
void displayHeapDijkstra(Heap * h);
/**
 * @brief Fonction d'affichage d'un noeud de tas
 * @param n Pointeur vers le noeud de tas à afficher
 */
void displayHeapNode(HeapNode * n);
/**
 * @brief Fonction d'affichage du tableau des positions
 * @param h Adresse vers le tas
 */
void displayPos(Heap * h);

/**
 * @brief Fonction qui calcule l'index du fils gauche d'un noeud
 * @param node Index du noeud courant
 * @return Index du fils gauche d'un noeud
 */
int getLeftChild(int node);
/**
 * @brief Fonction qui calcule l'index du fils droit d'un noeud
 * @param node Index du noeud courant
 * @return Index du fils droit d'un noeud
 */
int getRightChild(int node);
/**
 * @brief Fonction qui calcule l'index du parent d'un noeud
 * @param node Index du noeud courant
 * @return Index du parent d'un noeud
 */
int getParent(int node);

/**
 * @brief Fonction d'ajout à la fin du tas
 * @param h Pointeur vers le tas
 * @param n Pointeur vers le noeud à ajouter
 */
void heapAddEnd(Heap * h, HeapNode * n);
/**
 * @brief Fonction de percolation vers le haut
 * @param h Pointeur vers le tas
 * @param i Index du noeud à partir duquel on percole vers le haut
 */
void heapHeapifyUp(Heap * h, int i);
/**
 * @brief Fonction de percolation vers le bas
 * @param h Pointeur vers le tas
 * @param i Index du noeud à partir duquel on percole vers le bas
 */
void heapHeapifyDown(Heap * h, int i);
/**
 * @brief Fonction d'échange entre deux noeuds d'un tas
 * @param h Pointeur vers le tas
 * @param i Index du premier noeud
 * @param j Index du deuxième noeud
 */
void heapSwap(Heap * h, int i, int j);

/**
 * @brief Fonction d'ajout dans le tas et qui conserve les propriétés du tas
 * @param h Pointeur vers le tas
 * @param n Pointeur vers le noeud à ajouter
 */
void heapAdd(Heap * h, HeapNode * n);

/**
 * @brief Fonction qui teste l'existence d'un noeud de numéro i
 * @param h Pointeur vers le tas
 * @param i Numéro du noeud dont l'existence est à tester
 * @return 1 si le noeud existe, sinon 0.
 */
int heapNodeNumberExists(Heap * h, int i);

/**
 * @brief Fonction qui teste l'existence d'un noeud d'index i
 * @param h Pointeur vers le tas
 * @param i Numéro du noeud dont l'existence est à tester
 * @return 1 si le noeud existe, sinon 0.
 */
int heapNodeExists(Heap * h, int i);
/**
 * @brief Fonction d'extraction du minimum du tas
 * @param h Pointeur vers le tas
 * @return Pointeur vers le tas mis à jour
 */
HeapNode *heapExtractHead(Heap * h);
/**
 * @brief Fonction d'extraction du noeud d'index i du tas
 * @param h Pointeur vers le tas
 * @param i Index du noeud à extraire
 * @return Pointeur vers le tas mis à jour
 */
HeapNode *heapExtract(Heap * h, int i);
/**
 * @brief Fonction qui vérifie si un tas est vide
 * @param h Pointeur vers le tas
 * @return 1 si le tas est vide, sinon 0.
 */
int heapIsEmpty(Heap * h);
/**
 * @brief Fonction qui retourne l'index du noeud de numéro i
 * @param h Pointeur vers le tas
 * @param i Numéro à chercher
 * @return Index de la clef à chercher, 0 si non présent.
 */
int heapFindIndex(Heap * h, int i);
/**
 * @brief Fonction qui vérifie si le tas contient le noeud de clef i
 * @param h Pointeur vers le tas
 * @param i Clé à chercher
 * @return 1 si le tas contient le noeud de clef i, sinon 0.
 */
int heapContains(Heap *h, int i);

/* primitives required */
/**
 * @brief Fonction d'initialisation d'un tas
 * @param taille Taille maximale du tas
 * @return Tas initialisé
 */
Heap * initialiserTas(int taille);

/**
 * Fonction qui teste si le tas est vide
 * @param h Tas
 * @return 1 si la liste est vide, sinon 0
 */
int estVideTas(Heap * h);

/**
 * Fonction d'ajout d'un élément à la liste
 * @param h Tas
 * @param x Sommet à ajouter
 * @param l Longueur associée
 */
void ajouterElementTas(Heap * h, Sommet * x, int l);
/**
 * Fonction de suppression d'un noeud contenant un sommet précisé
 * @param h Tas
 * @param x Sommet à supprimer de la liste
 */
void supprimerElementTas(Heap * h, Sommet * x);
/**
 * Fonction de suppression d'un élément contenant un sommet précisé
 * @param h Tas
 * @param x Sommet à supprimer de la liste
 */
void supprimerElementTasMem(Heap * h, Sommet * x);
/**
 * @brief Fonction de récupération du minimum dans la liste
 * @param h Tas
 * @return Adresse vers le noeud minimum
 */
HeapNode * recupMinTas(Heap * h);
#endif
