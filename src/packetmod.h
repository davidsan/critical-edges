/**
 * \file packetmod.h
 * \brief En-tête de Paquet circulaire
 */

#ifndef PACKETMOD_H_
#define PACKETMOD_H_

#include "packet.h"

/**
 * @struct PaquetMod
 * Structure d'un paquet optimisé
 */
typedef struct paquetMod {
	Sommet * x;
	struct paquetMod * prec;
	struct paquetMod * suiv;
} PaquetMod;

/**
 * @struct EnsemblePaquetMod
 * Structure d'un ensemble de paquet optimisé
 */
typedef struct ensemblePaquetMod {
	int taille;
	int index;
	PaquetMod ** tab;
} EnsemblePaquetMod;

/**
 * @brief Fonction de création d'un paquet optimisé
 * @param x Adresse d'un sommet
 * @return Adresse vers le paquet crée
 */
PaquetMod * creerPaquetMod(Sommet * x);
/**
 * @brief Fonction de libération mémoire d'une liste de paquet optimisée
 * @param p Adresse de la liste de paquet à libérer
 */
void freePaquetMod(PaquetMod * p);
/**
 * @brief Fonction de création d'un ensemble de paquet optimisé
 * @param taille Taille du tableau des paquets
 * @return Adresse vers l'ensemble crée
 */
EnsemblePaquetMod * creerEnsemblePaquetMod(int taille);

/**
 * @brief Fonction de libération mémoire d'un ensemble de paquet
 * @param ens Adresse d'un ensemble de paquet
 */
void freeEnsemblePaquetMod(EnsemblePaquetMod * epm);

/* primitives required */
/**
 * @brief Fonction d'initialisation d'un ensemble de paquet
 * @param taille Taille du tableau des paquets
 * @return Adresse vers l'ensemble initialisé
 */
EnsemblePaquetMod * initialiserEnsemblePaquetMod(int taille);

/**
 * @brief Fonction qui teste si un epmemble est vide
 * @param epm Adresse d'un epmemble de paquet
 * @return 1 si l'ensemble est vide, sinon 0
 */
int estVideEnsemblePaquetMod(EnsemblePaquetMod * epm);

/**
 * @brief Fonction qui ajoute un élément à l'ensemble de paquets
 * @param epm Adresse d'un epmemble de paquet
 * @param x Adresse du sommet à ajouter
 * @param l Longueur minimale d'une chaine d'un sommet déterminé vers le sommet x
 */
void ajouterEnsemblePaquetMod(EnsemblePaquetMod * epm, Sommet * x, int l);

/**
 * @brief Fonction qui supprime un élément d' un epmemble de paquets et qui libère sa mémoire associée
 * @param epm Adresse d'un epmemble de paquet
 * @param x Adresse du sommet à supprimer
 * @param Longueur minimale d'une chaine d'un sommet déterminé vers le sommet x
 */
void supprimerEnsemblePaquetMod(EnsemblePaquetMod * epm, Sommet * x, int l);

/**
 * @brief Fonction qui supprime un élément d' un epmemble de paquets
 * @param epm Adresse d'un epmemble de paquet
 * @param x Adresse du sommet à supprimer
 * @param Longueur minimale d'une chaine d'un sommet déterminé vers le sommet x
 */
void supprimerEnsemblePaquetModMem(EnsemblePaquetMod * epm, Sommet * x, int l);

/**
 * @brief Fonction qui retourne l'élément minimal de l'ensemble de paquets
 * @param epm Adresse d'un epmemble de paquet
 * @return Adresse du paquet à récupérer
 */
PaquetMod * recupMinEnsemblePaquetMod(EnsemblePaquetMod * epm);

#endif /* PACKETMOD_H_ */
