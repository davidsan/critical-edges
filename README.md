# Critical edges
================

## Introduction
===============

On considère un graphe non-orienté connexe G=(S,A) valué par une fonction c qui associe à chaque arête un entier positif représentant son coût, ainsi que deux sommets distincts s et t. On note par n le nombre de sommets de G et m son nombre d'arêtes. Une arête est dite critique si sa suppression du graphe entraîne une dégradation (stricte) de la longueur (définie par la somme des coûts des arêtes de la chaîne) de la plus courte chaîne entre s et t. L'arête critique qui entraine la plus forte dégradation de la longueur de la plus courte chaîne entre s et t sera dite vitale. Nous nous intéressons ici au problème de la recherche d'une arête vitale dans un graphe G.

Le problème de la recherche d'une arête vitale dans un graphe trouve une application naturelle dans l'exploitation des réseaux de télécommunications. En effet, un réseau de télécommunications (téléphone, internet,…) peut être décrit comme un graphe où les sommets sont des clients ou des concentrateurs (hubs), et les arêtes sont les câbles liant des clients ou des concentrateurs. Chaque câble possède un débit maximal qui peut être vu comme un temps de transfert d'informations : ce temps constitue le coût d'une arête. L'existence d'une arête-câble vitale dans un réseau entre deux utilisateurs (et surtout entre deux concentrateurs) est une cause de mauvaise qualité de communication du réseau.

En effet, les algorithmes de routage des données dans le réseau auront tendance à sur-utiliser ce câble qui sera vite saturé, provoquant alors un ralentissement des communications. D'autre part, en cas de panne de cette liaison, les communications sont immédiatement dégradées : en effet, le re-routage des informations va devoir utiliser une chaîne plus lente pour router la même demande entre deux clients.

Le but de ce projet est d'étudier plusieurs versions d'un algorithme permettant de déterminer une arête vitale dans un graphe non-orienté, si elle existe. Une analyse théorique et expérimentale devra être menée pour définir et vérifier expérimentalement l'efficacité des implémentations proposées.

## Installation
===============

```$ make```
	
	
## Exécution
============

```
$ ./main
$ ./convertPostscript <gph-files>
$ ./convertPostscriptDijkstra <datastruct> <gph-files>
$ ./convertPostscriptCritical <datastruct> <gph-files>
$ ./convertTimer <datastruct> <gph-files>
```


## Instances
==========

Sample instances from [TSPLIB](http://comopt.ifi.uni-heidelberg.de/software/TSPLIB95/)


## Licence
==========

Copyright © 2012 Kamalraj Muruganathan, David San

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

