#include "AdjacencyMatrix.hpp"
#include <queue>
#include <climits>

Matrix::Matrix(int V) : V(V), adjMatrix(V, vector<int>(V, 0)) {}

void Matrix::addEdge(int x, int y, int weight)
{
    adjMatrix[x][y] = weight;
    adjMatrix[y][x] = weight;
}

int Matrix::getWeight(int x, int y)
{
    return adjMatrix[x][y];
}

void Matrix::removeEdge(int x, int y)
{
    adjMatrix[x][y] = 0;
    adjMatrix[y][x] = 0;
}

void Matrix::display()
{
    cout<<"~~~Adjacency Matrix~~~"<<endl;
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cout << adjMatrix[i][j] << "\t";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Matrix::dijkstra(int source)
{
    priority_queue < pair<int, int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;
    
    pq.push(make_pair(0, source));

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for(int v = 0; v < V; v++)
        {
            int weightemp = adjMatrix[u][v];    

            if(weightemp > 0 && dist[u] != INT_MAX && dist[v] >  dist[u] + weightemp)
            {
                dist[v] = dist[u] + weightemp;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    /*cout<<"Vertex distance from "<<source<<" to:"<<endl;
    for(int i = 0; i < V; i++)
    {
        cout << i << "\t" <<dist[i] << endl;
    }*/
}

void Matrix::shortestPath(int source, int destination)
{
    priority_queue < pair<int, int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;
    pq.push(make_pair(0,source));

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if(u == destination)
        {
            break;
        }

        for(int v=0; v<V; v++)
        {
            int weightemp = adjMatrix[u][v];    

            if(weightemp > 0 && dist[u] != INT_MAX && dist[v] >  dist[u] + weightemp)
            {
                dist[v] = dist[u] + weightemp;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "Shortest distance from " << source << " to " << destination <<" is " <<dist[destination]<<endl;
}