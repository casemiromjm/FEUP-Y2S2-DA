#include "../data_structures/Graph.h"
#include "stack"
using namespace std;

template <typename T>
vector<vector<T>> sccTarjan(Graph<T>* g) {
    vector<vector<T>> res;

    // dfs based

    // initialize variables
    for (auto v : g->getVertexSet()) {
        v->setVisited(false);
        v->setLow(-1);
        v->setNum(-1);
    }

    stack<T> s;
    // order in which the node was traversed
    int order = 0;

    for (auto v : g->getVertexSet()) {
        if (!v->isVisited()) {
            dfs_aux(v, order, s, res);
        }
    }

    return res;
}

/*
 * Auxiliary function to compute auxiliary variables
 */
template <typename T>
void dfs_aux(Vertex<T>*& v, int& order, stack<T>& s, vector<vector<T>>& sccs) {
    v->setVisited(true);
    s.push(v->getInfo());

    v->setLow(order); v->setNum(order); order++;

    for (auto e : v->getAdj()) {
        auto w = e->getDest();

        if (!w->isVisited()) {
            dfs_aux(w, order, s, sccs);
            v->setLow(min(v->getLow(), w->getLow()));
        }
        else {
            v->setLow(min(v->getLow(), w->getNum()));
        }
    }

    // there's a scc starting on v
    if (v->getLow() == v->getNum()) {
        vector<T> scc;
        T w;
        do {
            w = s.top();
            s.pop();
            scc.push_back(w);
        } while (w != v->getInfo());

        sccs.push_back(scc);
    }
}