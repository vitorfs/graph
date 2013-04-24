/*
 * =====================================================================================
 *
 *       Filename:  adjacency_list.h
 *
 *    Description:  Adjacency List Header with the required methods
 *
 *        Version:  1.0
 *        Created:  24/04/2013 10:27:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitor Freitas (vfs), vitorfs@gmail.com
 *        Company:  Universidade Federal de Juiz de Fora (UFJF)
 *
 * =====================================================================================
 */

typedef struct adj_list Adj_List;

struct adj_list {
  int vertex;
  Adj_List* next;
};

void empty_adjlist(Adj_List* g);
void exist_arc_adjlist(Adj_List* g, int v1, int v2);
void insert_arc_adjlist(Adj_List* g, int v1, int v2, int weight);
void remove_arc_adjlist(Adj_List* g, int v1, int v2);
void free_adjlist(Adj_List* g);
void print_adjlist(Adj_List* g);
void remove_min_arc(Adj_List* g);
