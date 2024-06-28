#ifndef ADJACENCYMATRIX_HPP
#define ADJACENCYMATRIX_HPP
#include "Graph.hpp"
#include <vector>

class Matrix : public Graph
{
private:
    int V; // number of vertices
    vector<vector<int> > adjMatrix;

public:
    Matrix(int V);
    void addEdge(int x, int y, int weight);
    void removeEdge(int x, int y);
    void display();
    void dijkstra(int source) ;
    void shortestPath(int source, int destination);
    int getWeight(int x, int y);
};

#endif