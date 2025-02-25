// Original code by Gonçalo Leão
// Updated by DA 2024/2025 Team

#include "../data_structures/Graph.h"
#include <queue>  // Include queue for BFS

template <class T>
void unweightedShortestPath(Graph<T> * g, const int &origin) {
    // TODO
}

template <class T>
static std::vector<T> getPath(Graph<T> * g, const int &origin, const int &dest) {
    std::vector<T> res;
    // TODO
    return res;
}

/// TESTS ///
#include <gtest/gtest.h>
#include <chrono>

template <class T>
static void checkAllPaths(Graph<T> &g, std::string expected) {
    std::stringstream ss;
    std::vector<Vertex<T> *> vs = g.getVertexSet();
    for(unsigned int i = 0; i < vs.size(); i++) {
        ss << vs[i]->getInfo() << "<-";
        if ( vs[i]->getPath() != nullptr ) {
            ss << vs[i]->getPath()->getOrig()->getInfo();
        }
        ss << "|";
    }
    EXPECT_EQ(expected, ss.str());
}

static void checkSinglePath(std::vector<int> path, std::string expected) {
    std::stringstream ss;
    for(unsigned int i = 0; i < path.size(); i++) {
        ss << path[i] << " ";
    }
    EXPECT_EQ(expected, ss.str());
}

TEST(TP3_Ex3, test_unweightedShortestPath) {
    Graph<int> myGraph;

    for(int i = 1; i <= 7; i++)
        myGraph.addVertex(i);

    myGraph.addEdge(1, 2, 1);
    myGraph.addEdge(1, 4, 1);
    myGraph.addEdge(2, 4, 1);
    myGraph.addEdge(2, 5, 1);
    myGraph.addEdge(3, 1, 1);
    myGraph.addEdge(3, 6, 1);
    myGraph.addEdge(4, 3, 1);
    myGraph.addEdge(4, 5, 1);
    myGraph.addEdge(4, 6, 1);
    myGraph.addEdge(4, 7, 1);
    myGraph.addEdge(5, 7, 1);
    myGraph.addEdge(6, 4, 1);
    myGraph.addEdge(7, 6, 1);

    unweightedShortestPath(&myGraph, 3);
    checkAllPaths(myGraph, "1<-3|2<-1|3<-|4<-1|5<-2|6<-3|7<-4|");

    unweightedShortestPath(&myGraph, 1);
    checkAllPaths(myGraph, "1<-|2<-1|3<-4|4<-1|5<-2|6<-4|7<-4|");
    checkSinglePath(getPath(&myGraph, 1, 7), "1 4 7 ");

    unweightedShortestPath(&myGraph,5);
    checkSinglePath(getPath(&myGraph, 5, 6), "5 7 6 ");

    unweightedShortestPath(&myGraph, 7);
    checkSinglePath(getPath(&myGraph, 7, 1), "7 6 4 3 1 ");

}