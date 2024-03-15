#include <iostream>
#include <vector>
#include <algorithm>
#include "graph.hpp"

//NEED TO ADD DESTRUCTORS FOR ALL CLASSES

Node::Node(){
    data = -1;
}

Edge::Edge(){
    weight = 0;
    end_A = nullptr;
    end_B = nullptr;
}

Graph::Graph(){
    empty = true;
}

Node *Graph::AddNode(int data){
    Node *new_node = new Node;
    new_node->data = data;
    graph_nodes.push_back(new_node);
    return new_node;
}

Edge *Graph::AddEdge(int weight, Node * start, Node * end){
    Edge *new_edge = new Edge;
    new_edge->weight = weight;
    new_edge->end_A = start;
    start->adjacent.push_back(new_edge);
    new_edge->end_B = end;
    end->adjacent.push_back(new_edge);
    graph_edges.push_back(new_edge);
    return new_edge;
}

bool Graph::IsConnected(){
    bool retval = true;
    for(int i = 0; i < graph_nodes.size(); i++){
        if(graph_nodes[i]->adjacent.size() < 1);
            retval = false;
    }   
    return retval;
}

Graph::MST::MST(){
    intialized = false;
}

bool Graph::MST::CompareEdgeWeights(Edge * A, Edge *B){
    return (A->weight < B->weight);
}

void Graph::MST::MSTFromGraph(const std::vector<Node*>& parent_nodes, const std::vector<Edge*>& parent_edges){
    //make a copy of parent edges to sort by weight
    std::vector<Edge *> sorted_edges = parent_edges;
    //sort the edges from smallest to largest by weight
    std::sort(sorted_edges.begin(), sorted_edges.end(), CompareEdgeWeights);

    int edge_index = 0;
    //while we have not included all nodes in the MST
    while (MST_nodes.size() < parent_nodes.size()){
        //add the next edge
        MST_edges.push_back(sorted_edges[edge_index]);
        //if the A side node from edge hasnt already been included add it
        if(std::count(MST_nodes.begin(), MST_nodes.end(), sorted_edges[edge_index]->end_A) < 1){
            MST_nodes.push_back(sorted_edges[edge_index]->end_A);
        }
        //if the B side node from edge hasnt already been included add it
        if(std::count(MST_nodes.begin(), MST_nodes.end(), sorted_edges[edge_index]->end_B) < 1){
            MST_nodes.push_back(sorted_edges[edge_index]->end_B);
        }
        //if the edge creates a cycle in the graph, backpedal and remove it
        if(MST_edges.size() >= MST_nodes.size()){
            MST_edges.pop_back();
        }

        edge_index++;
    }
    intialized = true;
};

Graph::ShortPath::ShortPath(){

}

void Graph::ShortPath::dijskras(Node * source){
    
}