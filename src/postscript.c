/**
 * \file postscript.c
 * \brief Source de postscript
 * \author David San
 */

#include "postscript.h"

int minX = INT_MAX, minY = INT_MAX;
float coefA4x = DPI_A4_X, coefA4y = DPI_A4_Y;

void writeGraphe(FILE * f, Graphe * G) {
	Arete * current = NULL;
	int i;
	float dimX = 0;
	float dimY = 0;
	coefA4x = DPI_A4_X;
	coefA4y = DPI_A4_Y;
	minX = INT_MAX;
	minY = INT_MAX;

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
		current = G->sommets[i]->voisins;
		while (current != NULL ) {
			drawLine(f,
					BORDER + minX * coefA4x + (int) (current->s1->x * coefA4x),
					BORDER + minY * coefA4y + (int) (current->s1->y * coefA4y),
					BORDER + minX * coefA4x + (int) (current->s2->x * coefA4x),
					BORDER + minY * coefA4y + (int) (current->s2->y * coefA4y));
			current = current->suivant;
		}
	}
	// écriture des sommets
	for (i = 0; i < G->nbSommets; i++) {
		drawCircle(f,
				BORDER + minX * coefA4x + (int) (G->sommets[i]->x * coefA4x),
				BORDER + minY * coefA4y + (int) (G->sommets[i]->y * coefA4y),
				DIAMETER);
	}
}

void writeDijkstra(FILE * f, Graphe * G, Arete * sp) {
	// écriture du sommet src en vert
	fillCircle(f,
			BORDER + minX * coefA4x + (int) (G->sommets[G->s]->x * coefA4x),
			BORDER + minY * coefA4y + (int) (G->sommets[G->s]->y * coefA4y),
			DIAMETER + 0.5, 0.0, 1.0, 0.0);
	// écriture du sommet dest en rouge
	fillCircle(f,
			BORDER + minX * coefA4x + (int) (G->sommets[G->t]->x * coefA4x),
			BORDER + minY * coefA4y + (int) (G->sommets[G->t]->y * coefA4y),
			DIAMETER + 0.5, 1.0, 0.0, 0.0);

	// écriture du + court chemin reliant src à dest
	Arete * current = sp;
	while (current) {
		setWhite(f);
		setLineWidth(f, 1);
		drawLine(f, BORDER + minX * coefA4x + (int) (current->s1->x * coefA4x),
				BORDER + minY * coefA4y + (int) (current->s1->y * coefA4y),
				BORDER + minX * coefA4x + (int) (current->s2->x * coefA4x),
				BORDER + minY * coefA4y + (int) (current->s2->y * coefA4y));

		drawCircle(f,
				BORDER + minX * coefA4x + (int) (current->s1->x * coefA4x),
				BORDER + minY * coefA4y + (int) (current->s1->y * coefA4y),
				DIAMETER + 1);
		drawCircle(f,
				BORDER + minX * coefA4x + (int) (current->s2->x * coefA4x),
				BORDER + minY * coefA4y + (int) (current->s2->y * coefA4y),
				DIAMETER + 1);
		current = current->suivant;
	}

}

void writeAreteVitale(FILE * f, Arete * vitale) {
	setRed(f);
	drawLine(f, BORDER + minX * coefA4x + (int) (vitale->s1->x * coefA4x),
			BORDER + minY * coefA4y + (int) (vitale->s1->y * coefA4y),
			BORDER + minX * coefA4x + (int) (vitale->s2->x * coefA4x),
			BORDER + minY * coefA4y + (int) (vitale->s2->y * coefA4y));

	drawCircle(f, BORDER + minX * coefA4x + (int) (vitale->s1->x * coefA4x),
			BORDER + minY * coefA4y + (int) (vitale->s1->y * coefA4y),
			DIAMETER + 1);
	drawCircle(f, BORDER + minX * coefA4x + (int) (vitale->s2->x * coefA4x),
			BORDER + minY * coefA4y + (int) (vitale->s2->y * coefA4y),
			DIAMETER + 1);

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
	setRGBColor(f, 1, 1, 1);
	fprintf(f, "%d %d %f 0 360 arc closepath\n", x, y, diameter);
	fprintf(f, "fill\n");
	fprintf(f, "stroke\n");
}

void fillCircle(FILE * f, int x, int y, float diameter, float r, float g,
		float b) {
	if (r + g + b < 1.5) {
		setWhite(f);
	} else {
		setBlack(f);
	}
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
	setRGBColor(f, 19. / 256, 51. / 256, 253. / 256);
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
	// setWhite(f);
}
