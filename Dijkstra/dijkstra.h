#pragma once
#include <vector>

class Graph{
private:
    int vertices;
    std::vector<std::vector<int> > adj;
public:
    explicit Graph(int v);
    void add_edge(int first, int second, int distance);
    void Dijkstra(int start);
};