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

#define INSERT_NODE 1
#define REMOVE_NODE 2
#define INSERT_ARC 3
#define REMOVE_ARC 4
#define REMOVE_MIN_ARC 5
#define TRANSPOSE_GRAPH 6
#define PRINT_GRAPH 7
#define EXIT 0

typedef struct {
  int node_count;
  int arc_count;
  int** arcs; // 0 represents the lack of adjacency
} Graph;

void empty_graph(Graph* g) {
  g->node_count = 0;
  g->arc_count = 0;
  g->arcs = NULL;
}

void init_graph(Graph* g, int n) {
  int i, j;
  
  empty_graph(g);

  g->node_count = n;

  g->arcs = (int**) malloc(n * sizeof(int*));
  for (i = 0 ; i < g->node_count ; i++)
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
  init_graph(transpose, g->node_count);

  int i, j;

  for (i = 0 ; i < g->node_count ; i++)
    for (j = 0 ; j < g->node_count ; j++)
      if (g->arcs[i][j] == 0)
        transpose->arcs[i][j] = 1;

  return transpose;
}

int insert_arc(Graph* g, int a1, int a2, int weight) {
  if (a1 >= 0 && a1 < g->node_count && a2 >= 0 && a2 < g->node_count && g->arcs[a1][a2] == 0) {
    g->arcs[a1][a2] = weight;
    g->arc_count++;
    return 0;
  }
  return -1;
}

int remove_arc(Graph* g, int a1, int a2) {
  int weight = -1;
  if (a1 >= 0 && a1 < g->node_count && a2 >= 0 && a2 < g->node_count && g->arcs[a1][a2] > 0) {
    weight = g->arcs[a1][a2];
    g->arcs[a1][a2] = 0;
    g->arc_count--;
  }
  return weight;
}

int exists_arc(Graph* g, int a1, int a2) {
  return g->arcs[a1][a2] > 0;
}

int* get_adjacency(Graph* g, int n) {
  return NULL;
}

int insert_node(Graph* g, int n) {
 
}

int remove_node(Graph* g, int n) {
 
}

void print_graph(Graph* g) {
  int i, j;

  for (i = 0 ; i < g->node_count ; i++) {
    for (j = 0 ; j < g->node_count ; j++) {
      printf("[%d]", g->arcs[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void menu() {
  system("clear");
  printf("Graph Theory\n");
  printf("[1] Insert Node\n");
  printf("[2] Remove Node\n");
  printf("[3] Insert Arc\n");
  printf("[4] Remove Arc\n");
  printf("[5] Remove Min Arc\n");
  printf("[6] Transpose Graph\n");
  printf("[7] Print Graph\n");
  printf("[0] Exit\n");
}

int main(int argc, char* argv[]) {
  Graph* g = (Graph*) malloc(sizeof(Graph));
  int option;

  do {
    menu();
    scanf("%d", &option);
    switch (option) {
      case PRINT_GRAPH:
        print_graph(g);
        break;
    }
  } while (option != EXIT);

  return 0;
}
