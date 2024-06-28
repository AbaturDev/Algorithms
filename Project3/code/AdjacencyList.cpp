#include "AdjacencyList.hpp"
#include <vector>
#include <queue>
#include <climits>

List::List(int V)
{
    this->V = V;
    adjList = new list<pair<int,int> >[V];
}

void List::addEdge(int start, int end, int weight)
{
    adjList[start].push_back(make_pair(end, weight));
    adjList[end].push_back(make_pair(start, weight));
}

void List::display()
{
    cout << "~~~Adjacency List~~~" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << ": ";
        for (auto edge : adjList[i])
        {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

void List::dijkstra(int source)
{
    priority_queue < pair<int, int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    pq.push(make_pair(0,source));

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for(auto edge : adjList[u])
        {
            int v = edge.first;
            int weightemp = edge.second;
            
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

void List::shortestPath(int source, int destination)
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

        for(auto edge : adjList[u])
        {
            int v = edge.first;
            int weightemp = edge.second;
            
            if(weightemp > 0 && dist[u] != INT_MAX && dist[v] >  dist[u] + weightemp)
            {
                dist[v] = dist[u] + weightemp;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "Shortest distance from " << source << " to " << destination <<" is " <<dist[destination]<<endl;
}