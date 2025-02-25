#include "../data_structures/Graph.h"
#include "stack"
using namespace std;

// Kosaraju-Sharir algorithm
template <typename T>
vector<vector<T>> SCCkosaraju(Graph<T>* g)  {
    vector<vector<T>> sccs;

    // dfs based

    for (auto v : g->getVertexSet()) {
        v->setVisited(false);
    }

    stack<Vertex<T> *> st;

    // traverse the original graph (dfs wise), putting the nodes on a stack
    for (auto v : g->getVertexSet()) {
        if (!v->isVisited()) {
            dfs_aux(v, st);
        }
    }

    // generate the reverse graph
    Graph<T> reverse_graph;

    for (auto v : g->getVertexSet()) {
        reverse_graph.addVertex(v->getInfo());
    }

    for (auto v : g->getVertexSet()) {
        for (auto e : v->getAdj()) {
            reverse_graph.addEdge(e->getDest()->getInfo(), e->getOrig()->getInfo(), e->getWeight());
        }
    }

    // reset "visited" flags
    for (auto v : reverse_graph.getVertexSet()) {
        v->setVisited(false);
    }

    // traverse the reverse graph
    while (!st.empty()) {
        auto v = st.top();
        st.pop();

        auto v_reverse = reverse_graph.findVertex(v->getInfo());
        if (v_reverse != nullptr && !v_reverse->isVisited()) {
            vector<T> scc;
            dfs_reverse(v_reverse, scc);
            sccs.push_back(scc);
        }
    }

    return sccs;
}
/*
 * Auxiliary function for performing a DFS starting on a certain vertex v.
 */
template <typename T>
void dfs_aux(Vertex<T>* v, stack<Vertex<T>*>& st) {
    v->setVisited(true);

    for (auto e : v->getAdj()) {
        auto w = e->getDest();

        if (!w->isVisited()) {
            dfs_aux(w, st);
        }
    }
    st.push(v);
}

/*
 * Auxiliary function for traversing the reverse graph and collecting vertices that belongs to the same SCC
 */
template <typename T>
void dfs_reverse(Vertex<T>* v, vector<T>& scc) {
    v->setVisited(true);
    scc.push_back(v->getInfo());

    for (auto e : v->getAdj()) {
        auto w = e->getDest();

        if (!w->isVisited()) {
            dfs_reverse(w, scc);
        }
    }
}


