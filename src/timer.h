/**
 * \file timer.h
 * \brief En-tête des timers
 * \author David San
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <time.h>
#include "reader.h"
#include "graph.h"
#include "postscript.h"
#include "dijkstra.h"
#include "solver.h"

void timeAll(char *filename);

void timeListe(char *filename);

void timeTas(char *filename);

void timePaquet(char *filename);

void timePaquetMod(char *filename);

#endif /* TIMER_H_ */
