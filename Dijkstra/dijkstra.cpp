#include "dijkstra.h"
#include <vector>
#include <iostream>

using namespace std;

Graph::Graph(int v) {
    this->vertices = v;
    adj.assign(v, vector<int>(v, 0));
}
void Graph::add_edge(int u, int v, int distance) {
    adj[u][v] = distance;
    adj[v][u] = distance;
}
void Graph::Dijkstra(int start) {
    vector<int> dist(vertices, INT_MAX);
    vector<bool> visited(vertices, false);
    dist[start] = 0;
    for (int i = 0;i < vertices;i++){
        int min = INT_MAX;
        int fixed;
        for (int j = 0;j < vertices;j++){
            if (!visited[j] && dist[j] < min){
                min = dist[j];
                fixed = j;
            }
        }
        visited[fixed] = true;
        for (int j = 0;j < vertices;j++){
            if (adj[fixed][j] == 0)
                continue;
            if (visited[j])
                continue;
            int newDistance = dist[fixed] + adj[fixed][j];
            if (newDistance < dist[j])
                dist[j] = newDistance;
        }
    }
    for(int m = 0;m < vertices;m++)
        cout << m << " " << dist[m] << endl;
}