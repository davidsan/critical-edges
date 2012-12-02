/**
 * \file timer.c
 * \brief Source des timers
 * \author David San
 */
#include "timer.h"

void timeAll(char *file) {
	fprintf(stderr, "%s ", file);
	timeListe(file);
	timeTas(file);
	timePaquet(file);
	// timePaquetMod(file);
	fprintf(stderr, "\n");

}

void timeListe(char *file) {
	clock_t temps_initial; /* Temps initial en micro-secondes */
	clock_t temps_final; /* Temps final en micro-secondes */
	float temps_cpu; /* Temps total en secondes */
	temps_initial = clock();
	/* action */
	FILE * f = NULL;
	FILE * output = NULL;
	Graphe * G = NULL;
	char *filename = NULL;
	f = ouvrirFichierRead(file);
	G = lectureGraphe(f);
	filename = basename(file);
	filename = strtok(filename, ".");
	filename = strcat(filename, ".ps");
	Dijkstra * D = dijkstraListe(G, G->s);
	Arete * sp = extractSP(G, D);
	Arete * vitale = NULL;
	vitale = solveListe(G, sp);
	output = ouvrirFichierWrite(filename);
	writeGraphe(output, G);
	writeDijkstra(output, G, sp);
	writeAreteVitale(output, vitale);
	fermerFichier(output);
	freeArete(vitale);
	freeArete(sp);
	freeDijkstra(D);
	freeGraphe(G);
	if (f) {
		fermerFichier(f);
	}
	/* fin action */
	temps_final = clock();
	temps_cpu = (temps_final - temps_initial) * 1e-6;
	fprintf(stderr, "%f ", temps_cpu);
}

void timeTas(char *file) {
	clock_t temps_initial; /* Temps initial en micro-secondes */
	clock_t temps_final; /* Temps final en micro-secondes */
	float temps_cpu; /* Temps total en secondes */
	temps_initial = clock();
	/* action */
	FILE * f = NULL;
	FILE * output = NULL;
	Graphe * G = NULL;
	char *filename = NULL;
	f = ouvrirFichierRead(file);
	G = lectureGraphe(f);
	filename = basename(file);
	filename = strtok(filename, ".");
	filename = strcat(filename, ".ps");
	Dijkstra * D = dijkstraTas(G, G->s);
	Arete * sp = extractSP(G, D);
	Arete * vitale = NULL;
	vitale = solveTas(G, sp);
	output = ouvrirFichierWrite(filename);
	writeGraphe(output, G);
	writeDijkstra(output, G, sp);
	writeAreteVitale(output, vitale);
	fermerFichier(output);
	freeArete(vitale);
	freeArete(sp);
	freeDijkstra(D);
	freeGraphe(G);
	if (f) {
		fermerFichier(f);
	}
	/* fin action */
	temps_final = clock();
	temps_cpu = (temps_final - temps_initial) * 1e-6;
	fprintf(stderr, "%f ", temps_cpu);
}

void timePaquet(char *file) {
	clock_t temps_initial; /* Temps initial en micro-secondes */
	clock_t temps_final; /* Temps final en micro-secondes */
	float temps_cpu; /* Temps total en secondes */
	temps_initial = clock();
	/* action */
	FILE * f = NULL;
	FILE * output = NULL;
	Graphe * G = NULL;
	char *filename = NULL;
	f = ouvrirFichierRead(file);
	G = lectureGraphe(f);
	filename = basename(file);
	filename = strtok(filename, ".");
	filename = strcat(filename, ".ps");
	Dijkstra * D = dijkstraPaquet(G, G->s);
	Arete * sp = extractSP(G, D);
	Arete * vitale = NULL;
	vitale = solvePaquet(G, sp);
	output = ouvrirFichierWrite(filename);
	writeGraphe(output, G);
	writeDijkstra(output, G, sp);
	writeAreteVitale(output, vitale);
	fermerFichier(output);
	freeArete(vitale);
	freeArete(sp);
	freeDijkstra(D);
	freeGraphe(G);
	if (f) {
		fermerFichier(f);
	}
	/* fin action */
	temps_final = clock();
	temps_cpu = (temps_final - temps_initial) * 1e-6;
	fprintf(stderr, "%f ", temps_cpu);
}

void timePaquetMod(char *file) {
	clock_t temps_initial; /* Temps initial en micro-secondes */
	clock_t temps_final; /* Temps final en micro-secondes */
	float temps_cpu; /* Temps total en secondes */
	temps_initial = clock();
	/* action */
	FILE * f = NULL;
	FILE * output = NULL;
	Graphe * G = NULL;
	char *filename = NULL;
	f = ouvrirFichierRead(file);
	G = lectureGraphe(f);
	filename = basename(file);
	filename = strtok(filename, ".");
	filename = strcat(filename, ".ps");
	Dijkstra * D = dijkstraPaquetMod(G, G->s);
	Arete * sp = extractSP(G, D);
	Arete * vitale = NULL;
	vitale = solvePaquetMod(G, sp);
	output = ouvrirFichierWrite(filename);
	writeGraphe(output, G);
	writeDijkstra(output, G, sp);
	writeAreteVitale(output, vitale);
	fermerFichier(output);
	freeArete(vitale);
	freeArete(sp);
	freeDijkstra(D);
	freeGraphe(G);
	if (f) {
		fermerFichier(f);
	}
	/* fin action */
	temps_final = clock();
	temps_cpu = (temps_final - temps_initial) * 1e-6;
	fprintf(stderr, "%f ", temps_cpu);
}

