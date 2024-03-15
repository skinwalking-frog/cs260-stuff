#include <iostream>
#include <vector>

class Node {
    private:

    public:
    int data;
    std::vector<Edge *> adjacent;

    Node();
    ~Node();
};

class Edge {
    private:

    public:
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

    bool empty;

    std::vector<Node *> graph_nodes;
    std::vector<Edge *> graph_edges;
    
    Graph();
    ~Graph();
    Node *AddNode(int);
    Edge *AddEdge(int, Node *, Node *);
    bool IsConnected();

};

class Graph::MST {
    private:

    public:
    bool intialized;
    std::vector<Node *> MST_nodes;
    std::vector<Edge *> MST_edges;

    MST();
    ~MST();

    bool CompareEdgeWeights(Edge *, Edge *);
    void MSTFromGraph(const std::vector<Node*>&, const std::vector<Edge*>&);
};

class Graph::ShortPath {
    private:

    public:
    std::vector<Node *> previous;
    std::vector<Node *> distance;

    ShortPath();
    void dijskras(Node *);
};