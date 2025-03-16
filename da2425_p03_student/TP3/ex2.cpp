// Original code by Gonçalo Leão
// Updated by DA 2024/2025 Team

#include "MSTTestAux.h"
#include "../data_structures/UFDS.h"

template <class T>
bool compareEdgesKruskal(const Edge<T>* e1, const Edge<T>* e2) {
    return e1->getWeight() < e2->getWeight();
}

/**
 * Auxiliary function to set the "path" field to make a spanning tree.
 */
template <typename T>
void dfsKruskalPath(Vertex<T> *v) {
    v->setVisited(true);

    for (auto e : v->getAdj()) {
        auto w = e->getDest();

        if (e->isSelected() && !w->isVisited()) {
            w->setPath(e);
            dfsKruskalPath(w);
        }
    }
}

template <typename T>
std::vector<Vertex<T> *> kruskal(Graph<T> *g) {

    if (g->getVertexSet().empty()) {
        return g->getVertexSet();   // no minimal spanning tree
    }

    UFDS ufds(g->getNumVertex());
    std::vector<Edge<T> *> edges;
    unsigned int edgesCount = 0;

    // initialize variables
    for (auto v : g->getVertexSet()) {
        v->setVisited(false);
        v->setPath(nullptr);

        for (auto e : v->getAdj()) {
            e->setSelected(false);

            if (e->getOrig()->getInfo() < e->getDest()->getInfo()) {
                edges.push_back(e);
            }
        }
    }

    // sorts edges by non-decreasing order (x >= y, x being the one before y)
    sort(edges.begin(), edges.end(), compareEdgesKruskal<T>);

    // kruskal
    for (auto e : edges) {
        auto orig = e->getOrig();
        auto dest = e->getDest();

        if (!ufds.isSameSet(orig->getInfo(), dest->getInfo())) {
            ufds.linkSets(orig->getInfo(), dest->getInfo());

            e->setSelected(true);
            e->getReverse()->setSelected(true);

            edgesCount++;

            if (edgesCount == g->getNumVertex()-1) {
                break;
            }
        }
    }

    // makes the first node as the initial
    g->getVertexSet()[0]->setPath(nullptr);
    // set path of the spanning tree
    dfsKruskalPath(g->getVertexSet()[0]);

    return g->getVertexSet();
}

/// TESTS ///
#include <gtest/gtest.h>
#include <chrono>

TEST(TP3_Ex2, test_kruskal) {
    Graph<int> graph = createMSTTestGraph<int>();
    std::vector<Vertex<int> *> res = kruskal(&graph);

    std::stringstream ss;
    for(const auto v : res) {
        ss << v->getInfo() << "<-";
        if ( v->getPath() != nullptr ) {
            ss << v->getPath()->getOrig()->getInfo();
        }
        ss << "|";
    }
    std::cout << ss.str() << std::endl;

    EXPECT_TRUE(isSpanningTree(res));
    EXPECT_EQ(spanningTreeCost(res), 11);
}

TEST(TP3_Ex2_performance, test_performance_kruskal) {
    //Change these const parameters as needed
    const int MIN_SIZE = 10;
    const int MAX_SIZE = 30; //Try with 100
    const int STEP_SIZE = 10;
    const int N_REPETITIONS = 50;
    for (int n = MIN_SIZE; n <= MAX_SIZE; n += STEP_SIZE) {
        Graph<int> g;
        generateRandomGridGraph(n, g);
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 1; i <= N_REPETITIONS; i++)
            kruskal(&g);
        auto finish = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
        std::cout << "Processing grid (Kruskal) " << n << " x " << n << " average time (milliseconds)=" << (elapsed / N_REPETITIONS) << std::endl;
    }
}
