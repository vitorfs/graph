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
#include "graph.h"

void empty_graph(Graph* g) {
  g->vertex_count = 0;
  g->arcs = NULL;
}

void init_graph(Graph* g, int n) {
  int i, j;
  
  empty_graph(g);

  g->vertex_count = n;

  g->arcs = (int**) malloc(n * sizeof(int*));
  for (i = 0 ; i < g->vertex_count ; i++)
    g->arcs[i] = (int*) malloc(n * sizeof(int));

  for (i = 0 ; i < n ; i++)
    for (j = 0 ; j < n ; j++)
      g->arcs[i][j] = 0;
}

void free_graph(Graph* g) {
  free(g);
}

Graph* transpose_graph(Graph* g) {
  Graph* transpose = (Graph*) malloc(sizeof(Graph));
  init_graph(transpose, g->vertex_count);

  int i, j;

  for (i = 0 ; i < g->vertex_count ; i++)
    for (j = 0 ; j < g->vertex_count ; j++)
      if (g->arcs[i][j] == 0)
        transpose->arcs[i][j] = 1;

  return transpose;
}

int insert_arc(Graph* g, int a1, int a2, int weight) {
  if (a1 >= 0 && a1 < g->vertex_count && a2 >= 0 && a2 < g->vertex_count && g->arcs[a1][a2] == 0) {
    g->arcs[a1][a2] = weight;
    g->arcs[a2][a1] = weight;
    return 0;
  }
  return -1;
}

int remove_arc(Graph* g, int a1, int a2) {
  int weight = -1;
  if (a1 >= 0 && a1 < g->vertex_count && a2 >= 0 && a2 < g->vertex_count && g->arcs[a1][a2] > 0) {
    weight = g->arcs[a1][a2];
    g->arcs[a1][a2] = 0;
    g->arcs[a2][a1] = 0;
  }
  return weight;
}

int exists_arc(Graph* g, int a1, int a2) {
  return g->arcs[a1][a2] > 0;
}

int* get_adjacency(Graph* g, int v) {
  return NULL;
}

void insert_vertex(Graph* g, int v) {
  if (g->arcs == NULL) {
    init_graph(g, v); 
  }

  else {
    int i, j;
    g->vertex_count += v;
    g->arcs = (int**) realloc(g->arcs, g->vertex_count * sizeof(int*));
    
    for (i = 0 ; i < g->vertex_count - v ; i++)
      g->arcs[i] = (int*) realloc(g->arcs[i], g->vertex_count * sizeof(int)); // realloc the part of the matrix which were used before

    for ( ; i < g->vertex_count ; i++) 
      g->arcs[i] = (int*) malloc(g->vertex_count * sizeof(int)); // alloc the new part of the matrix

    for (i = 0 ; i < g->vertex_count ; i++) {
      for (j = g->vertex_count - v ; j < g->vertex_count ; j++) {
        g->arcs[i][j] = 0;
        g->arcs[j][i] = 0;
      }
    }
  }
}

int remove_vertex(Graph* g, int v) {
 
}

void print_graph(Graph* g) {
  int i, j;

  for (i = 0 ; i < g->vertex_count ; i++) {
    for (j = 0 ; j < g->vertex_count ; j++) {
      printf("[%d]", g->arcs[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

