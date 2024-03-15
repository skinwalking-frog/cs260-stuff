#include <iostream>
#include <vector>
#include <map>

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
    void print();
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
    void print();
};

class Graph::ShortPath {
    private:

    public:
    bool initialized;

    std::vector<Node *> Q;
    std::vector<Node *> visited;
    std::vector<Node *> unvisited;
    std::map<Node *, Node *> previous;
    std::map<Node*, int> distance;

    ShortPath();
    ~ShortPath();
    void dijkstras(Node *, const std::vector<Node*>&, const std::vector<Edge*>&);
    void print();
};

