#include "dijkstra.h"

using namespace std;

int main(){
    Graph graph(7);
    graph.add_edge(0, 1, 7);
    graph.add_edge(0, 5, 3);
    graph.add_edge(5, 1, 9);
    graph.add_edge(5, 4, 11);
    graph.add_edge(1, 3, 4);
    graph.add_edge(1, 2, 2);
    graph.add_edge(3, 2, 8);
    graph.add_edge(4, 2, 16);
    graph.add_edge(2, 6, 12);
    graph.Dijkstra(0);
}