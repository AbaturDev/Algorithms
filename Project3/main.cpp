#include <iostream>
#include <initializer_list>
#include "AdjacencyList.hpp"
#include "AdjacencyMatrix.hpp"
#include "Test.hpp"

using namespace std;

int main()
{
    Graph *g;
    Matrix m(9);
    List l(9);

    g = &l;

    g->addEdge(0, 1, 4);
    g->addEdge(0, 7, 8);
    g->addEdge(1, 2, 8);
    g->addEdge(1, 7, 11);
    g->addEdge(2, 3, 7);
    g->addEdge(2, 8, 2);
    g->addEdge(2, 5, 4);
    g->addEdge(3, 4, 9);
    g->addEdge(3, 5, 14);
    g->addEdge(4, 5, 10);
    g->addEdge(5, 6, 2);
    g->addEdge(6, 7, 1);
    g->addEdge(6, 8, 6);
    g->addEdge(7, 8, 7);
    g->display();
    g->dijkstra(0);
    g->shortestPath(0,5);

    return 0;
}