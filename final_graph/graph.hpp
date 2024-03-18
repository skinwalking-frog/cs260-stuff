#include <iostream>
#include <vector>
#include <map>
#include <queue>

class Edge;
class Node;

class Node {
    private:

    public:
    int data;
    int ID;
    std::vector<Edge *> adjacent;

    Node();
    ~Node();
};

class Edge {
    private:

    public:
    int ID;
    int weight;
    Node *end_A;
    Node *end_B;

    Edge();
    ~Edge();
};

class Graph {
    private:

    public:
    class MST;
    class ShortPath;

    MST * MinSpanTree;
    ShortPath * Dijkstra;

    int edge_ID_count;
    int node_ID_count;

    std::vector<Node *> graph_nodes;
    std::vector<Edge *> graph_edges;
    
    Graph();
    ~Graph();

    Node *AddNode(int);
    Edge *AddEdge(int, Node *, Node *);
    bool IsConnected();
    void print();
};

class Graph::MST {
    private:

    public:
    bool initialized;

    std::vector<Node *> MST_nodes_1;
    std::vector<Edge *> MST_edges_1;

    MST();
    ~MST();

    // bool CompareEdgeWeights(Edge *, Edge *);
    void MSTFromGraph(const std::vector<Node*>&, const std::vector<Edge*>&);
    void print();
};

class Graph::ShortPath {
    private:

    public:
    bool initialized;
    
    std::map<Node *, Node *> previous;
    std::map<Node*, int> distance;

    ShortPath();
    ~ShortPath();
    void dijkstras(Node *, const std::vector<Node*>&, const std::vector<Edge*>&);
    void print(std::vector<Node *> );
};

