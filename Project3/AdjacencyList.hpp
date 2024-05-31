#ifndef ADJACENCYLIST_HPP
#define ADJACENCYLIST_HPP
#include "Graph.hpp"
#include <list>

class List : public Graph
{
private:
    int V; //number of vertices
    list<pair<int,int> > *adjList;

public:
    List(int V);
    void addEdge(int x, int y, int weight);
    void display();
    void dijkstra(int source);
    void shortestPath(int source, int destination);
};

#endif