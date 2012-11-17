/**
 * \file liste.c
 * \brief Source de liste
 */

#include "liste.h"

Element * creerElement(Sommet * x, int l) {
	Element * new = (Element *) malloc(sizeof(Element));
	new->x = x;
	new->l = l;
	new->next = NULL;
	return new;
}

Liste * creerListe() {
	Liste * new = (Liste *) malloc(sizeof(Liste));
	new->hd = NULL;
	return new;
}

void freeElement(Element * e) {
	if (e) {
		freeElement(e->next);
		free(e);
	}
}

void freeListe(Liste * list) {
	if (list) {
		freeElement(list->hd);
		free(list);
	}
}

void display(Liste * list) {
	if (!list) {
		fprintf(stderr, "display : liste non initialisée");
		return;
	}
	Element * current = list->hd;
	while (current) {
		fprintf(stdout, "%d %d %d %d\n", current->x->numero, current->x->x,
				current->x->y, current->l);
		current = current->next;
	}

}

Liste * initialiser() {
	return creerListe();
}

int est_vide(Liste * list) {
	return list && list->hd == NULL ;
}

void ajouter(Liste * list, Sommet * x, int l) {
	if (!list) {
		fprintf(stderr, "ajouter : liste non initialisée");
		return;
	}
	Element * e = creerElement(x, l);
	// empty
	if (est_vide(list)) {
		list->hd = e;
		return;
	}
	// before current hd
	if (list->hd->l > e->l) {
		e->next = list->hd;
		list->hd = e;
		return;
	}
	Element * prev = list->hd;
	Element * current = list->hd->next;
	while (current && current->l < e->l) {
		prev = current;
		current = current->next;
	}
	prev->next = e;
	e->next = current;
}

void supprimer(Liste * list, Sommet * x) {
	if (!list) {
		fprintf(stderr, "supprimer : liste non initialisée");
		return;
	}
	Element * rem = NULL;
	if (list->hd->x == x) {
		rem = list->hd;
		list->hd = list->hd->next;
		free(rem);
		return;
	}
	Element * previous = list->hd;
	Element * current = previous->next;
	while (current) {
		if (current->x == x) {
			previous->next = current->next;
			free(current);
			return;
		}
		current = current->next;
	}
}

Element * recup_min(Liste * list) {
	if (!list) {
		fprintf(stderr, "recup_min : liste non initialisée");
		return NULL ;
	}
	return list->hd;
}

