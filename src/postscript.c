/**
 * \file postscript.c
 * \brief Source de postscript
 * \author David San
 */

#include "postscript.h"

void writeGraphe(char * filename, Graphe * G) {
	FILE * f = NULL;
	Arete * curseur = NULL;
	int i;
	float diameter = 1.5;
	float coefA4x = DPI_A4_X, coefA4y = DPI_A4_Y;
	float dimX = 0, dimY = 0;
	int minX = INT_MAX, minY = INT_MAX;
	// ouverture fichier
	f = ouvrirFichierWrite(filename);
	for (i = 0; i < G->nbSommets; i++) {
		if (dimX < G->sommets[i]->x) {
			dimX = G->sommets[i]->x;
		}
		if (dimY < G->sommets[i]->y) {
			dimY = G->sommets[i]->y;
		}
		if (minX > G->sommets[i]->x) {
			minX = G->sommets[i]->x;
		}
		if (minY > G->sommets[i]->y) {
			minY = G->sommets[i]->y;
		}
	}
	minX *= -1;
	minY *= -1;
	dimX += minX;
	dimY += minY;
	coefA4x = (float) (coefA4x - BORDER * 2) / dimX;
	coefA4y = (float) (coefA4y - BORDER * 2) / dimY;
	// écriture du graphe
	setCustomParamPostscript(f);
	fillBg(f, DPI_A4_X, DPI_A4_Y);
	// écriture des aretes
	setAreteColor(f);
	for (i = 0; i < G->nbSommets; i++) {
		curseur = G->sommets[i]->voisins;
		while (curseur != NULL ) {
			drawLine(f,
					BORDER + minX * coefA4x + (int) (curseur->s1->x * coefA4x),
					BORDER + minY * coefA4y + (int) (curseur->s1->y * coefA4y),
					BORDER + minX * coefA4x + (int) (curseur->s2->x * coefA4x),
					BORDER + minY * coefA4y + (int) (curseur->s2->y * coefA4y));
			curseur = curseur->suivant;
		}
	}
	// écriture des sommets
	for (i = 0; i < G->nbSommets; i++) {
		drawCircle(f,
				BORDER + minX * coefA4x + (int) (G->sommets[i]->x * coefA4x),
				BORDER + minY * coefA4y + (int) (G->sommets[i]->y * coefA4y),
				diameter);
	}
	// fermeture fichier
	fermerFichier(f);
}

void writeGrapheDijkstra(char * filename, Graphe * G, Arete * sp) {
	FILE * f = NULL;
	Arete * curseur = NULL;
	int i;
	float diameter = 1.5;
	float coefA4x = DPI_A4_X, coefA4y = DPI_A4_Y;
	float dimX = 0, dimY = 0;
	int minX = INT_MAX, minY = INT_MAX;
	// ouverture fichier
	f = ouvrirFichierWrite(filename);
	for (i = 0; i < G->nbSommets; i++) {
		if (dimX < G->sommets[i]->x) {
			dimX = G->sommets[i]->x;
		}
		if (dimY < G->sommets[i]->y) {
			dimY = G->sommets[i]->y;
		}
		if (minX > G->sommets[i]->x) {
			minX = G->sommets[i]->x;
		}
		if (minY > G->sommets[i]->y) {
			minY = G->sommets[i]->y;
		}
	}
	minX *= -1;
	minY *= -1;
	dimX += minX;
	dimY += minY;
	coefA4x = (float) (coefA4x - BORDER * 2) / dimX;
	coefA4y = (float) (coefA4y - BORDER * 2) / dimY;
	// écriture du graphe
	setCustomParamPostscript(f);
	fillBg(f, DPI_A4_X, DPI_A4_Y);
	// écriture des aretes
	setAreteColor(f);
	for (i = 0; i < G->nbSommets; i++) {
		curseur = G->sommets[i]->voisins;
		while (curseur != NULL ) {
			drawLine(f,
					BORDER + minX * coefA4x + (int) (curseur->s1->x * coefA4x),
					BORDER + minY * coefA4y + (int) (curseur->s1->y * coefA4y),
					BORDER + minX * coefA4x + (int) (curseur->s2->x * coefA4x),
					BORDER + minY * coefA4y + (int) (curseur->s2->y * coefA4y));
			curseur = curseur->suivant;
		}
	}
	// écriture des sommets
	for (i = 0; i < G->nbSommets; i++) {
		drawCircle(f,
				BORDER + minX * coefA4x + (int) (G->sommets[i]->x * coefA4x),
				BORDER + minY * coefA4y + (int) (G->sommets[i]->y * coefA4y),
				diameter);
	}

	// écriture du sommet src en vert
	fillCircle(f,
			BORDER + minX * coefA4x + (int) (G->sommets[G->s]->x * coefA4x),
			BORDER + minY * coefA4y + (int) (G->sommets[G->s]->y * coefA4y),
			diameter + 0.5, 0.0, 1.0, 0.0);
	// écriture du sommet dest en rouge
	fillCircle(f,
			BORDER + minX * coefA4x + (int) (G->sommets[G->t]->x * coefA4x),
			BORDER + minY * coefA4y + (int) (G->sommets[G->t]->y * coefA4y),
			diameter + 0.5, 1.0, 0.0, 0.0);
	// écriture du + court chemin raliant src à dest
	curseur = sp;
	while (curseur) {
		setWhite(f);
		setLineWidth(f, 0.5);
		drawLine(f, BORDER + minX * coefA4x + (int) (curseur->s1->x * coefA4x),
				BORDER + minY * coefA4y + (int) (curseur->s1->y * coefA4y),
				BORDER + minX * coefA4x + (int) (curseur->s2->x * coefA4x),
				BORDER + minY * coefA4y + (int) (curseur->s2->y * coefA4y));
		setLineWidth(f, 0.1);
		drawCircle(f,
				BORDER + minX * coefA4x + (int) (curseur->s1->x * coefA4x),
				BORDER + minY * coefA4y + (int) (curseur->s1->y * coefA4y),
				diameter + 0.5);
		drawCircle(f,
				BORDER + minX * coefA4x + (int) (curseur->s2->x * coefA4x),
				BORDER + minY * coefA4y + (int) (curseur->s2->y * coefA4y),
				diameter + 0.5);
		curseur = curseur->suivant;
	}
	// fermeture fichier
	fermerFichier(f);
}

void fillBg(FILE *f, int width, int height) {
	setBgColor(f);
	fprintf(f, "newpath\n");
	fprintf(f, "%d %d moveto\n", 0, 0);
	fprintf(f, "%d %d lineto\n", width, 0);
	fprintf(f, "%d %d lineto\n", width, height);
	fprintf(f, "%d %d lineto\n", 0, height);
	fprintf(f, "%d %d lineto\n", 0, 0);
	fprintf(f, "closepath\n");
	fprintf(f, "fill\n");
}

void drawLine(FILE * f, int x1, int y1, int x2, int y2) {
	fprintf(f, "%d %d moveto\n", x1, y1);
	fprintf(f, "%d %d lineto\n", x2, y2);
	fprintf(f, "stroke\n");
}

void drawCircle(FILE * f, int x, int y, float diameter) {
	setBlack(f);
	fprintf(f, "%d %d %f 0 360 arc closepath\n", x, y, diameter + 0.5);
	fprintf(f, "fill\n");
	fprintf(f, "stroke\n");
	setWhite(f);
	fprintf(f, "%d %d %f 0 360 arc closepath\n", x, y, diameter);
	fprintf(f, "fill\n");
	fprintf(f, "stroke\n");
}

void fillCircle(FILE * f, int x, int y, float diameter, float r, float g,
		float b) {
	setBlack(f);
	fprintf(f, "%d %d %f 0 360 arc closepath\n", x, y, diameter + 0.5);
	fprintf(f, "fill\n");
	fprintf(f, "stroke\n");
	setRGBColor(f, r, g, b);
	fprintf(f, "%d %d %f 0 360 arc closepath\n", x, y, diameter);
	fprintf(f, "fill\n");
	fprintf(f, "stroke\n");
}

void setLineWidth(FILE *f, float width) {
	fprintf(f, "%f setlinewidth\n", width);
}

void setCustomParamPostscript(FILE * f) {
	fprintf(f, "<< /PageSize [842 595] >> setpagedevice\n");
	setLineWidth(f, 0.1);
}

void setRGBColor(FILE * f, float r, float g, float b) {
	fprintf(f, "%f %f %f setrgbcolor\n", r, g, b);
}

void setBlack(FILE * f) {
	setRGBColor(f, 0, 0, 0);
}

void setWhite(FILE * f) {
	setRGBColor(f, 1, 1, 1);
}

void setRed(FILE * f) {
	setRGBColor(f, 1, 0, 0);
}

void setGreen(FILE * f) {
	setRGBColor(f, 0, 1, 0);
}

void setBlue(FILE * f) {
	setRGBColor(f, 0, 0, 1);
}

void setLightBlue(FILE *f) {
	setRGBColor(f, 19.0 / 256, 51.0 / 256, 253.0 / 256);
}

void setDarkBlue(FILE *f) {
	setRGBColor(f, 0, 0, 11.0 / 256);
}

void setAreteColor(FILE *f) {
	setLightBlue(f);
	//setBlack(f);
}

void setBgColor(FILE *f) {
	setDarkBlue(f);
	//setWhite(f);
}
