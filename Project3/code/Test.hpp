#ifndef TEST_HPP
#define TEST_HPP
#include "AdjacencyList.hpp"
#include "AdjacencyMatrix.hpp"
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace chrono;

void generateList(List& l,int vertices, int edges, int max)
{
    srand(time(NULL));
    int temp = 0;

    while(temp <= edges)
    {
        int start = (rand() % vertices) + 0;
        int end = (rand() % vertices) + 0;

        if(start != end)
        {
            int weight = (rand() % max) + 0;
            l.addEdge(start, end, weight);
            temp++;
        }
    }
}

void generateMatrix(Matrix& m, int vertices, int edges, int max)
{
    srand(time(NULL));
    int temp = 0;

    while(temp <= edges)
    {
        int start = (rand() % vertices) + 0;
        int end = (rand() % vertices) + 0;

        if(start != end && m.getWeight(start, end) == 0)
        {
            int weight = (rand() % max) + 0;
            m.addEdge(start, end, weight)  ;
            temp++;
        }
    }
}

void measureList(int vertices, int edges, int max)
{
    double time = 0;
    for(int i = 0; i<100; i++)
    {
        List l(vertices);
        generateList(l, vertices, edges, max);

        auto start = high_resolution_clock::now();
        l.dijkstra(0);
        auto stop = high_resolution_clock::now();
	    auto duration = duration_cast<microseconds>(stop - start);
        time += duration.count();
    }
    cout<<time/100<<"us"<<endl;
}

void measureMartix(int vertices, int edges, int max)
{
    double time = 0;
    for(int i = 0; i < 100; i++)
    {
        Matrix m(vertices);
        generateMatrix(m, vertices, edges, max);

        auto start = high_resolution_clock::now();
        m.dijkstra(0);
        auto stop = high_resolution_clock::now();
	    auto duration = duration_cast<microseconds>(stop - start);
        time += duration.count();
    }
    cout<<time/100<<"us"<<endl;
}

#endif