#include <vector>
#include <map>

class Graph {
    private:
        /*
            The graph is directed. In the following map,
            the key is an integer identifier for each URL
            and the value is a list of vertices adjacent to the key vertex.
        */
        std::map<std::string, std::vector<std::string>> adjList;
    public:
        void PageRank(int n);
        void InsertEdge(std::string from, std::string to);
        std::vector<std::string> GetAdjacent(std::string vertex);
};

