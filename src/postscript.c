/**
 * \file postscript.c
 * \brief Source de postscript
 * \author David San
 */

#include "postscript.h"

void writeGraphe(char * filename, Graphe * G) {
	srand(time(NULL ));
	FILE * f = NULL;
	int i;
	float diameter = 1.5;
	int border = 20;
	int dpiA4x = 842, dpiA4y = 595;
	float coefA4x = dpiA4x, coefA4y = dpiA4y;
	float dimX = 0, dimY = 0;
	int minX = INT_MAX, minY = INT_MAX;
	Arete * curseur = NULL;
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

	coefA4x = (float) (coefA4x - border * 2) / dimX;
	coefA4y = (float) (coefA4y - border * 2) / dimY;
	// écriture du graphe
	setCustomParamPostscript(f);
	fillBg(f, dpiA4x, dpiA4y);

	// écriture des aretes
	setAreteColor(f);
	curseur = G->aretes;
	while (curseur != NULL ) {
		drawLine(f, border + minX * coefA4x + (int) (curseur->s1->x * coefA4x),
				border + minY * coefA4y + (int) (curseur->s1->y * coefA4y),
				border + minX * coefA4x + (int) (curseur->s2->x * coefA4x),
				border + minY * coefA4y + (int) (curseur->s2->y * coefA4y));
		curseur = curseur->suivant;
	}

	// écriture des sommets
	setWhite(f);
	for (i = 0; i < G->nbSommets; i++) {
		drawCircle(f,
				border + minX * coefA4x + (int) (G->sommets[i]->x * coefA4x),
				border + minY * coefA4y + (int) (G->sommets[i]->y * coefA4y),
				diameter);
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
	fprintf(f, "%d %d %f 0 360 arc closepath\n", x, y, diameter);
	fprintf(f, "fill\n");
	fprintf(f, "stroke\n");
}

void setCustomParamPostscript(FILE * f) {
	fprintf(f, "<< /PageSize [842 595] >> setpagedevice\n");
	fprintf(f, "0.01 setlinewidth\n");

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
}

void setBgColor(FILE *f) {
	setDarkBlue(f);
}
