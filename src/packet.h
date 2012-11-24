/**
 * \file packet.h
 * \brief En-tête de Paquet
 */
#ifndef PACKET_H_
#define PACKET_H_

#include "graph.h"

/**
 * @struct Paquet
 * Structure d'un paquet
 */
typedef struct paquet {
	Sommet * x;
	struct paquet * prec;
	struct paquet * suiv;
} Paquet;

/**
 * @struct EnsemblePaquet
 * Structure d'un ensemble de paquet
 */
typedef struct ensemblePaquet {
	int taille;
	Paquet ** tab;
} EnsemblePaquet;

/**
 * @brief Fonction de création d'un paquet
 * @param x Adresse d'un sommet
 * @return Adresse vers le paquet crée
 */
Paquet * creerPaquet(Sommet * x);

/**
 * @brief Fonction de création d'un ensemble de paquet
 * @param taille Taille du tableau des paquets
 * @return Adresse vers l'ensemble crée
 */
EnsemblePaquet * creerEnsemblePaquet(int taille);

/**
 * @brief Fonction de libération mémoire d'une liste de paquet
 * @param p Adresse d'un paquet à libérer
 */
void freePaquet(Paquet * p);

/**
 * @brief Fonction de libération mémoire d'un ensemble de paquet
 * @param ens Adresse d'un ensemble de paquet
 */
void freeEnsemblePaquet(EnsemblePaquet * ens);

/**
 * @brief Fonction d'affichage d'un paquet
 * @param p Adresse d'un paquet à afficher
 */
void afficherPaquet(Paquet * p);

/**
 * @brief Fonction d'affichage d'un ensemble de paquet
 * @param ens Adresse d'un ensemble de paquet
 */
void afficherEnsemblePaquet(EnsemblePaquet * ens);

/* primitives required */
/**
 * @brief Fonction d'initialisation d'un ensemble de paquet
 * @param taille Taille du tableau des paquets
 * @return Adresse vers l'ensemble initialisé
 */
EnsemblePaquet * initialiserEnsemblePaquet(int taille);

/**
 * @brief Fonction qui teste si un ensemble est vide
 * @param ens Adresse d'un ensemble de paquet
 * @return 1 si l'ensemble est vide, sinon 0
 */
int estVideEnsemblePaquet(EnsemblePaquet * ens);

/**
 * @brief Fonction qui ajoute un élément à l'ensemble de paquets
 * @param ens Adresse d'un ensemble de paquet
 * @param x Adresse du sommet à ajouter
 * @param l Longueur minimale d'une chaine d'un sommet déterminé vers le sommet x
 */
void ajouterEnsemblePaquet(EnsemblePaquet * ens, Sommet * x, int l);

/**
 * @brief Fonction qui supprime un élément d' un ensemble de paquets et qui libère sa mémoire associée
 * @param ens Adresse d'un ensemble de paquet
 * @param x Adresse du sommet à supprimer
 * @param Longueur minimale d'une chaine d'un sommet déterminé vers le sommet x
 */
void supprimerEnsemblePaquet(EnsemblePaquet * ens, Sommet * x, int l);

/**
 * @brief Fonction qui supprime un élément d' un ensemble de paquets
 * @param ens Adresse d'un ensemble de paquet
 * @param x Adresse du sommet à supprimer
 * @param Longueur minimale d'une chaine d'un sommet déterminé vers le sommet x
 */
void supprimerEnsemblePaquetMem(EnsemblePaquet * ens, Sommet * x, int l);

/**
 * @brief Fonction qui retourne l'élément minimal de l'ensemble de paquets
 * @param ens Adresse d'un ensemble de paquet
 * @return Adresse du paquet à récupérer
 */
Paquet * recupMinEnsemblePaquet(EnsemblePaquet * ens);

#endif /* PACKET_H_ */
