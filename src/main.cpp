#include <iostream>
#include <string>
#include "Graph.h"
using namespace std;

int main() {
    Graph graph;
    int lineNum, powerIters;
    std::string from, to;
    std::cin >> lineNum;
    std::cin >> powerIters;
    for(int i = 0; i < lineNum; i++)
    {
        std::cin >> from;
        std::cin >> to;
        graph.InsertEdge(from, to);
    }

    graph.PageRank(powerIters);
}