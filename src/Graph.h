#include <vector>
#include <map>
#include <set>

class Graph {
    private:
        /*
            The graph is directed. In the following map,
            the key is an integer identifier for each URL
            and the value is a list of vertices adjacent to the key vertex.
        */
        std::map<std::string, std::vector<std::string>> adjList;
        std::set<std::string> uniquePages;
    public:
        void PageRank(int n);
        void InsertEdge(std::string from, std::string to);
};