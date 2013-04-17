/*
 * =====================================================================================
 *
 *       Filename:  graph.h
 *
 *    Description:  Graph Header with the required methods
 *
 *        Version:  1.0
 *        Created:  17/04/2013 10:37:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitor Freitas (vfs), vitorfs@gmail.com
 *        Company:  Universidade Federal de Juiz de Fora (UFJF)
 *
 * =====================================================================================
 */

#ifndef GRAPH_H
#define GRAPH_H
typedef struct {
  int node_count;
  int arc_count;
  int** arcs; // 0 represents the lack of adjacency
} Graph;

void empty_graph(Graph* g);
void init_graph(Graph* g, int n);
void free_graph(Graph* g);
Graph* transpose_graph(Graph* g);
int insert_arc(Graph* g, int a1, int a2, int weight);
int remove_arc(Graph* g, int a1, int a2);
int exists_arc(Graph* g, int a1, int a2);
int* get_adjacency(Graph* g, int n);
int insert_node(Graph* g, int n);
int remove_node(Graph* g, int n);
void print_graph(Graph* g);
#endif
