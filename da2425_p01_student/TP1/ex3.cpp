#include <iostream>
#include "../data_structures/Graph.h"

using namespace std;

/****************** isDAG  ********************/
/*
 * Performs a depth-first search in a graph, to determine if the graph
 * is acyclic (acyclic directed graph or DAG).
 * During the search, a cycle is found if an edge connects to a vertex
 * that is being processed in the stack of recursive calls.
 * Returns true if the graph is acyclic, and false otherwise.
 */

template <class T>
bool isDAG(Graph<T> *g) {

    for (auto v : g->getVertexSet()) {

        if (dfsIsDAG(v)) {

            return false;
        }

        v->setProcessing(false);
    }

    return true;
}

/**
 * Auxiliary function that visits a vertex (v) and its adjacent, recursively.
 * Returns false (not acyclic) if an edge to a vertex in the stack is found.
 */
template <class T>
bool dfsIsDAG(Vertex<T> *v) {

    v->setProcessing(true);
    v->setVisited(true);

    for (auto e : v->getAdj()) {
        auto w = e->getDest();

        if (w->isVisited()) {
            return false;
        }

        dfsISDAG(w);
    }


    return true;
}

