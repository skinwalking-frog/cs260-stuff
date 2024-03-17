#include <iostream>
#include "graph.hpp"
//create the graph form the wikipedia page for dijkstras algorithm
int main(){
    Graph * graph = new Graph;
    //create nodes
    Node * node1 = graph->AddNode(1);
    Node * node2 = graph->AddNode(2);
    Node * node3 = graph->AddNode(3);
    Node * node4 = graph->AddNode(4);
    Node * node5 = graph->AddNode(5);
    Node * node6 = graph->AddNode(6);

    //create edges
    Edge * edge1 = graph->AddEdge(7, node1, node2);
    Edge * edge1 = graph->AddEdge(9, node1, node3);
    Edge * edge1 = graph->AddEdge(14, node1, node6);
    Edge * edge1 = graph->AddEdge(10, node2, node3);
    Edge * edge1 = graph->AddEdge(15, node2, node4);
    Edge * edge1 = graph->AddEdge(2, node3, node6);
    Edge * edge1 = graph->AddEdge(11, node3, node4);
    Edge * edge1 = graph->AddEdge(6, node4, node5);
    Edge * edge1 = graph->AddEdge(9, node5, node6);
    
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

    return 0;
}