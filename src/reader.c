/**
 * \file fichier.c
 * \brief Source de fichier
 * \author David San
 */
#include "reader.h"

FILE *ouvrirFichierRead(char *filename) {
	FILE *f = fopen(filename, "r");
	if (!f) {
		fprintf(stderr,
				"ouvrirFichierRead : erreur d'ouverture du fichier %s\n",
				filename);
		return NULL ;
	}
	return f;
}

FILE *ouvrirFichierWrite(char *filename) {
	FILE *f = fopen(filename, "w");
	if (!f) {
		fprintf(stderr,
				"ouvrirFichierWrite : erreur d'ouverture du fichier %s\n",
				filename);
		return NULL ;
	}
	return f;
}

void fermerFichier(FILE * f) {
	fclose(f);
}

int readLine(FILE * f, char *buffer) {
	return (fgets(buffer, BUFFER_SIZE, f) != NULL );
}

