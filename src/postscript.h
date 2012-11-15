/**
 *
 * \file postscript.h
 * \brief En-tête de postscript
 */

#ifndef POSTSCRIPT_H_
#define POSTSCRIPT_H_

#include <time.h>
#include <limits.h>
#include "graph.h"
#include "reader.h"

/**
 * @brief Fonction de conversion d'un graphe vers une réprésentation graphique PostScript
 * @param filename Nom du fichier de sortie
 * @param G Adresse du graphe
 */
void writeGraphe(char * filename, Graphe * G);

/**
 * @brief Fonction de remplissage de l'arrière plan
 * @param f Nom du fichier de sortie
 * @param width Largeur
 * @param height Hauteur
 */
void fillBg(FILE *f, int width, int height);

/**
 * @brief Fonction de dessin d'une ligne entre deux points
 * @param f Nom du fichier de sortie
 * @param x1 Coordonnée x du premier point
 * @param y1 Coordonnée y du premier point
 * @param x2 Coordonnée x du deuxième point
 * @param y2 Coordonnée y du deuxième point
 */
void drawLine(FILE * f, int x1, int y1, int x2, int y2);

/**
 * @brief Fonction de dessin d'un cercle
 * @param f Nom du fichier de sortie
 * @param x Coordonnée x du cercle
 * @param y Coordonnée y du cercle
 * @param diameter Diamètre du cercle
 */
void drawCircle(FILE * f, int x, int y, float diameter);

/**
 * @brief Fonction de définition des paramètres de sortie du fichier PostScript
 * @param f Nom du fichier de sortie
 */
void setCustomParamPostscript(FILE * f);

/**
 * @brief Fonction qui définit la couleur courante avec les composantes RGB
 * @param f Nom du fichier de sortie
 * @param r Composante rouge (en pourcentage)
 * @param g Composante verte (en pourcentage)
 * @param b Composante bleu (en pourcentage)
 */
void setRGBColor(FILE * f, float r, float g, float b);

/**
 * @brief Fonction qui définit la couleur courante par du noir
 * @param f Nom du fichier de sortie
 */
void setBlack(FILE * f);

/**
 * @brief Fonction qui définit la couleur courante par du blanc
 * @param f Nom du fichier de sortie
 */
void setWhite(FILE * f);

/**
 * @brief Fonction qui définit la couleur courante par du rouge
 * @param f Nom du fichier de sortief
 */
void setRed(FILE * f);

/**
 * @brief Fonction qui définit la couleur courante par du vert
 * @param f Nom du fichier de sortie
 */
void setGreen(FILE * f);

/**
 * @brief Fonction qui définit la couleur courante par du bleu
 * @param f Nom du fichier de sortief
 */
void setBlue(FILE * f);

/**
 * @brief Fonction qui définit la couleur courante par du bleu clair
 * @param f Nom du fichier de sortie
 */
void setLightBlue(FILE * f);

/**
 * @brief Fonction qui définit la couleur courante par du bleu foncé
 * @param f Nom du fichier de sortie
 */
void setDarkBlue(FILE * f);

/**
 * @brief Fonction qui définit la couleur courante avec la couleur des arêtes
 * @param f Nom du fichier de sortie
 */
void setAreteColor(FILE *f);

/**
 * @brief Fonction qui définit la couleur courante avec la couleur de l'arrière plan
 * @param f Nom du fichier de sortie
 */
void setBgColor(FILE *f);

#endif /* POSTSCRIPT_H_ */
