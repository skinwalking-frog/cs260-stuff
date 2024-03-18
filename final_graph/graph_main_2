#include <iostream>
#include "graph.hpp"
#include <limits>
#include <algorithm>
//create a very simple graph for testing (the one from my design p3)
int main(){
    Graph * graph = new Graph;
    //create nodes
    Node * node1 = graph->AddNode(1);
    Node * node2 = graph->AddNode(2);
    Node * node3 = graph->AddNode(3);
    Node * node4 = graph->AddNode(4);

    //create edges
    Edge * edge1 = graph->AddEdge(7, node1, node2);
    Edge * edge2 = graph->AddEdge(5, node1, node3);
    Edge * edge3 = graph->AddEdge(1, node2, node3);
    Edge * edge4 = graph->AddEdge(2, node2, node4);
    Edge * edge5 = graph->AddEdge(3, node3, node4);

    //print graph
    graph->print();

    //run MST
    graph->MinSpanTree->MSTFromGraph(graph->graph_nodes, graph->graph_edges);

    //print MST
    graph->MinSpanTree->print();
    
    //run dijkstra 
    graph->Dijkstra->dijkstras(node1, graph->graph_nodes, graph->graph_edges);

    //print dijkstra
    graph->Dijkstra->print(graph->graph_nodes);
    
    std::cout << "MAIN ran successfully!\n";

    return 0;
}