#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>
#include <set>
#include "Graph.h"
using namespace std;

void Graph::PageRank(int n) {
    // Initializng to 1/|V|
    const double initialRank = 1.0 / this->uniquePages.size();
    map<string, double> pageRank;

    // Applying initial PageRank values. Include all unique pages.
    for (const auto& entry: this->uniquePages) {
        pageRank[entry] = initialRank;
    }

    /*
        Performing power iterations
        Note that rank = SUM(rank of incoming vertice / outdegrees of incoming vertex)
    */
    for (int i = 0; i < n - 1; i++) {
        map<string, double> newPageRank;
        for (const auto& entry: this->uniquePages) {
            const string& curPage = entry;
            double newRank = 0.0;
            double multFactor = 0.0;

            for (const auto& entry: this->adjList) {
                if (curPage == entry.first) { // no self-loops, so disregard
                    continue;
                }
                else if (std::count(entry.second.begin(), entry.second.end(), curPage)) { // if curPage is adjacent to iterated page
                    newRank += (pageRank[entry.first] / (double) entry.second.size());
                }
            }
            newPageRank[curPage] = newRank;
        }

        pageRank.swap(newPageRank);
    }

    // Printing PageRank values in ascending alphabetical order
    for (const auto& entry : pageRank) {
        cout << entry.first << " " << fixed << setprecision(2) << entry.second << endl;
    }
}

void Graph::InsertEdge(string from, string to) {
   this->adjList[from].push_back(to);
   this->uniquePages.insert(from);
   this->uniquePages.insert(to);
}

vector<string> Graph::GetAdjacent(string vertex) {
    vector<string> vertices;
    if (this->adjList.find(vertex) == this->adjList.end()) { // base case
        return vertices;
    }

    for (const auto& edge: this->adjList[vertex]) {
        vertices.push_back(edge);
    }

    sort(vertices.begin(), vertices.end());
    return vertices;
}