#include <iostream>
#include "../data_structures/Graph.h"

using namespace std;

/****************** DFS ********************/
/*
 * Performs a depth-first search (dfs) in a graph from the source node.
 * Returns a vector with the contents of the vertices by dfs order.
 */
template <class T>
vector<T> dfs(Graph<T> *g, const T & source) {
    vector<int> res;

    auto v = g->findVertex(source);

    if (v == nullptr) return res;

    dfsVisit(v, res);

    return res;
}

/*
 * Auxiliary function that visits a vertex (v) and its adjacent, recursively.
 * Updates a parameter with the list of visited node contents.
 */
template <class T>
void dfsVisit(Vertex<T> *v, vector<T> & res) {

    v->setVisited(true);
    res.push_back(v->getInfo());

    for (auto e : v->getAdj()) {
        auto w = e->getDest();

        if (!w->isVisited()) {
            dfsVisit(w, res);
        }
    }

}

/****************** BFS ********************/
/*
 * Performs a breadth-first search (bfs) in a graph, starting
 * from the vertex with the given source contents (source).
 * Returns a vector with the contents of the vertices by bfs order.
 */
template <typename T>
vector<T> bfs(Graph<T> *g, const T & source) {
    vector<int> res;

    auto v = g->findVertex(source);
    if (v == nullptr) return res;

    queue<Vertex<T> *> q;    // unvisited nodes
    q.push(v);

    while (!q.empty()) {
        auto w = q.front(); q.pop();
        w->setVisited(true);
        res.push_back(w->getInfo());

        for (auto e : w->getAdj()) {
            auto u = e->getDest();
            if (!u->isVisited()) {
                q.push(u);
                u->setVisited(true);
            }
        }
    }

    return res;
}