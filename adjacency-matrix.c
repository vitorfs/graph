/*
 * =====================================================================================
 *
 *       Filename:  adjacency-matrix.c
 *
 *    Description:  Graph implementation using an Adjacency Matrix
 *
 *        Version:  1.0
 *        Created:  15/04/2013 14:27:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitor Freitas (vfs), vitorfs@gmail.com
 *        Company:  Universidade Federal de Juiz de Fora (UFJF)
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int node_count;
  int arc_count;
  int** arcs; // -1 represents the lack of adjacency
} Graph;

Graph empty_graph() {
  Graph g;

  g.node_count = 0;
  g.arc_count = 0;
  g.arcs = NULL;

  return g;
}

Graph insert_arc(Graph g, int v1, int v2, int weight) {
  g.arcs[v1][v2] = weight;
  return g;
}

void print_graph(Graph g) {
  int i, j;

  for (i = 0 ; i < g.node_count ; i++) {
    for (j = 0 ; j < g.node_count ; j++) {
      printf("[%2d]", g.arcs[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main(int argc, char* argv[]) {
  Graph g;

  g = empty_graph();
  
  int i, j;

  g.node_count = 5;

  g.arcs = (int**) malloc(g.node_count * sizeof(int*));
  for (i = 0 ; i < g.node_count ; i++) {
    g.arcs[i] = (int*) malloc(g.node_count * sizeof(int));
  }

  for (i = 0 ; i < g.node_count ; i++)
    for (j = 0 ; j < g.node_count ; j++)
      g.arcs[i][j] = -1;

  g = insert_arc(g, 0, 1, 5);
  print_graph(g);
  g = insert_arc(g, 2, 3, 10);
  print_graph(g);

  return 0;
}
