#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>
#include "Graph.h"
using namespace std;

void Graph::PageRank(int n) {
    // Initializng to 1/|V|
    const double initialRank = 1.0 / this->adjList.size();

    // Applying initial PageRank values
    map<string, double> pageRank;
    for (const auto& entry: this->adjList) {
        pageRank[entry.first] = initialRank;
    }

    /*
        Performing power iterations
        In each iteration, the current rank is multiplied by summation of 1/outdegree of all vertices to which the current node is adjacent.
        The summation is handled below via a multiplication factor which is applied after all pages are checked for references to the curPage
    */
    for (int i = 0; i < n - 1; i++) {
        map<string, double> newPageRank;
        for (const auto& entry: this->adjList) {
            const string& curPage = entry.first;
            double newRank = pageRank[curPage];
            double multFactor = 0.0;

            for (const auto& entry: this->adjList) {
                if (curPage == entry.first) { // no self-loops, so disregard
                    continue;
                }
                else if (std::count(entry.second.begin(), entry.second.end(), curPage)) { // if curPage is adjacent to iterated page
                    multFactor += (1 / (double) entry.second.size());
                }
            }
            newRank *= multFactor;
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