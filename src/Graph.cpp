#include <string>
#include <algorithm>
#include "Graph.h"
using namespace std;

void Graph::PageRank(int n) {
}

void Graph::InsertEdge(string from, string to) {
   this->adjList[from].push_back(to);
}

std::vector<string> Graph::GetAdjacent(string vertex) {
    std::vector<string> vertices;
    if (this->adjList.find(vertex) == this->adjList.end()) { // base case
        return vertices;
    }

    for (const auto& edge: this->adjList[vertex]) {
        vertices.push_back(edge);
    }

    std::sort(vertices.begin(), vertices.end());
    return vertices;
}