Graph Theory
============

Graph implementation using C. This repository have study purpose only.

The main program is defined on the **graph.c** file.
When compiling the program you should choice which implementation you want to use, for example:

    gcc graph.c adjacency-matrix.c

Adjacency Matrix
----------------
Assuming *n* as the number of vertex we have:

    Memory usage:     O(n^2)
    Verify adjacency: O(1)
    Visit every arc:  O(n^2)

Adjacency List
--------------
Assuming *n* as the number of vertex and *m* as the number of arcs, we have:

    Memory usage:     O(m+n)
    Verify adjacency: O(n)
    Visit every arc:  O(m)
