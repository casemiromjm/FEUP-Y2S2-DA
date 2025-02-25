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
    vector<T> res;

    // g must be a DAG -> must implement cycle detection
    // should use kahn's algorithm!!!!

    for (auto v : g->getVertexSet()) {
        v->setIndegree(v->getIncoming().size());
    }

    queue<Vertex<T>*> q;

    for (auto v : g->getVertexSet()) {
        if (v->getIndegree() == 0) {
            q.push(v);
        }
    }

    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        res.push_back(u->getInfo());

        for (auto e : u->getAdj()) {
            auto w = e->getDest();

            // simulates a node removal without actually handling its removal
            w->setIndegree(w->getIndegree()-1);

            if (w->getIndegree() == 0) {
                q.push(w);
            }
        }
    }

    if (res.size() != g->getVertexSet().size()) {
        return vector<T>();
    }

    return res;
}