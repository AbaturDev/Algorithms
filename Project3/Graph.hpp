#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
using namespace std;

class Graph
{
public:
    virtual void addEdge(int x, int y, int weight) = 0;
    virtual void display() = 0;
    virtual void dijkstra(int source) = 0;
    virtual void shortestPath(int source, int destination) = 0; 
};

#endif