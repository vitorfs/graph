/*
 * =====================================================================================
 *
 *       Filename:  adjacency_matrix.h
 *
 *    Description:  Adjacency Matrix Header with the required methods
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
  int vertex_count;
  int** arcs; // 0 represents the lack of adjacency
} Adjacency_Matrix;

void empty_graph(Adjacency_Matrix* g);
void init_graph(Adjacency_Matrix* g, int v);
void free_graph(Adjacency_Matrix* g);
Adjacency_Matrix* transpose_graph(Adjacency_Matrix* g);
int insert_arc(Adjacency_Matrix* g, int a1, int a2, int weight);
int remove_arc(Adjacency_Matrix* g, int a1, int a2);
int exists_arc(Adjacency_Matrix* g, int a1, int a2);
int* get_adjacency(Adjacency_Matrix* g, int v);
void insert_vertex(Adjacency_Matrix* g, int v);
int remove_vertex(Adjacency_Matrix* g, int v);
void print_graph(Adjacency_Matrix* g);
void print_adjacency(int* a);
#endif
