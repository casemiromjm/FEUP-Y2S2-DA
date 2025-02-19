#include <iostream>
#include "../data_structures/Graph.h"

using namespace std;

/*
 * Performs a topological sorting of the vertices of a graph.
 * Returns a vector with the contents of the vertices by topological order.
 * If the graph has cycles, returns an empty vector.
*/
template <typename T>
vector<T> topsort(Graph<T> *g) {
    vector<int> res;

    // g must be a DAG -> must implement cycle detection
    // should use kahn's algorithm!!!!

    for (auto v : g->getVertexSet()) {
        v->setIndegree(v->getIncoming().size());
    }


    return res;
}