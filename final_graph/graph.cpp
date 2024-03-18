#include <iostream>
// #include <vector>
// #include <queue>
#include <algorithm>
#include "graph.hpp"
#include <limits>
// #include <functional>
// #include <memory>

//NEED TO ADD DESTRUCTORS FOR ALL CLASSES

struct CompareEdgeWeights{
    bool operator()(const Edge* lhs, const Edge* rhs) const {
        return lhs->weight > rhs->weight;
    }
};

Node::Node(){
    data = -1;
    ID = -1;
}

Edge::Edge(){
    weight = 0;
    ID = -1;
    end_A = nullptr;
    end_B = nullptr;
}

Graph::Graph(){
    edge_ID_count = 0;
    node_ID_count = 0;
    MinSpanTree = new Graph::MST;
    Dijkstra = new Graph::ShortPath;
}

Node *Graph::AddNode(int data){
    Node *new_node = new Node;
    new_node->data = data;
    new_node->ID = node_ID_count;
    node_ID_count++;
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
    new_edge->ID = edge_ID_count;
    edge_ID_count++;
    graph_edges.push_back(new_edge);
    return new_edge;
}

bool Graph::IsConnected(){
    bool retval = true;
    for(int i = 0; i < graph_nodes.size(); i++){
        if(graph_nodes[i]->adjacent.size() < 1){
            retval = false;
        }
    }   
    return retval;
}

void Graph::print(){
    std::cout << "Graph\n";
    std::cout << "Nodes:\n";
    for(int i = 0; i < graph_nodes.size(); i++){
        std::cout << "node index: " << graph_nodes[i]->ID << " Data: " << graph_nodes[i]->data << std::endl;
    }

    std::cout << "edges:\n";
    for(int k = 0; k < graph_edges.size(); k++){
        std::cout << "Edge index: " << graph_edges[k]->ID << " node at end_A: " << graph_edges[k]->end_A->ID << " node at end_B: " << graph_edges[k]->end_B->ID << std::endl;
    }

}


Graph::MST::MST(){
    initialized = false;
    // MST_edges; //interacting with these vectors in any way causes a seg fault
    // MST_nodes;
    MST_nodes_1 = std::vector<Node*>();
    MST_edges_1 = std::vector<Edge*>();
}

void Graph::MST::MSTFromGraph(const std::vector<Node*>& parent_nodes, const std::vector<Edge*>& parent_edges){
    //on every run reset the spanning tree contents to nothing

    //####for some unknown reason running the code commented out below causes a seg fault####
    // if(MST_nodes.empty() == false && MST_edges.empty() == false){
    //     MST_nodes.clear();
    //     MST_edges.clear();
    // }else{
    //     std::cout << "initializing new MST\n";
    // }
    
    std::vector<Node *> MST_nodes = Graph::MST::MST_nodes_1;
    std::vector<Edge *> MST_edges = Graph::MST::MST_edges_1;

    // std::cout << "MST code mark 1\n";
    
    std::vector<Node *> cleaned_nodes = parent_nodes;
    int total_nodes = parent_nodes.size();
    
    for(int i = 0; i < total_nodes; i++){
        if(cleaned_nodes[i]->adjacent.size() < 1){
            cleaned_nodes.erase(cleaned_nodes.begin() + i);
            i--;
        }
    }

    // std::cout << "MST code mark 2\n";
    // std::cout << MST_nodes.size() << std::endl;

    //make a copy of parent edges to sort by weight
    std::vector<Edge *> sorted_edges = parent_edges;
    //sort the edges from smallest to largest by weight
    std::sort(sorted_edges.begin(), sorted_edges.end(), CompareEdgeWeights());

    // std::cout << "MST code mark 3\n";

    int edge_index = 0;
    //while we have not included all nodes in the MST
    while (MST_nodes.size() < cleaned_nodes.size()){
        // std::cout << "while loop running\n";
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
    initialized = true;
    // std::cout << "MST code ran\n";

    MST_edges_1 = MST_edges;
    MST_nodes_1 = MST_nodes;

};

void Graph::MST::print(){
    //debug...remove
    std::vector<Node *> MST_nodes = Graph::MST::MST_nodes_1;
    std::vector<Edge *> MST_edges = Graph::MST::MST_edges_1;

    std::cout << "MST\n";
    std::cout << "Nodes:\n";
    for(int i = 0; i < MST_nodes.size(); i++){
        std::cout << "node index: " << MST_nodes[i]->ID << " Data: " << MST_nodes[i]->data << std::endl;
    }

    std::cout << "edges:\n";
    for(int k = 0; k < MST_edges.size(); k++){
        std::cout << "Edge index: " << MST_edges[k]->ID << " node at end_A: " << MST_edges[k]->end_A->ID << " node at end_B: " << MST_edges[k]->end_B->ID << std::endl;
    }
}

Graph::ShortPath::ShortPath(){
    initialized = false;
}

void Graph::ShortPath::dijkstras(Node * source, const std::vector<Node*>& parent_nodes, const std::vector<Edge*>& parent_edges){
    //remove nodes that have no edges attached from algorithm input
    std::vector<Node *> cleaned_nodes = parent_nodes;
    for(int i = 0; i < parent_nodes.size(); i++){
        if(cleaned_nodes[i]->adjacent.size() < 1){
            cleaned_nodes.erase(cleaned_nodes.begin() + i);
            i--;
        }
    }
    
    for(int n = 0; n < cleaned_nodes.size(); n++){
        previous.insert_or_assign(cleaned_nodes[n], nullptr); 
    }

    for(int n = 0; n < cleaned_nodes.size(); n++){
        distance.insert_or_assign(cleaned_nodes[n], INT_MAX); 
    }

    //make vector of visited edges
    std::vector<Edge *> visited_edges;
    //make vector of visited nodes
    std::vector<Node *> visited_nodes;

    //IDK what the second half of this line really does, but Chat GPT said it would work ¯\_(ツ)_/¯
    std::priority_queue<Edge *, std::vector<Edge *>, CompareEdgeWeights> Q;
    
    distance.at(source) = 0;
    //add all atached edges from source to priority queue
    for(int i = 0; i < source->adjacent.size(); i++){
        Q.push(source->adjacent[i]);
    }

    //add the source to the visited list
    visited_nodes.push_back(source);
    //set progenitor to the source
    Node * progenitor = source;
    //while we still have edges in the Q to check
    while (Q.size() > 0){
        Edge * to_check = Q.top();
        Q.pop();
        //if end A is not a visited node, use it as the node to visit
        if(std::count(visited_nodes.begin(), visited_nodes.end(), to_check->end_A) < 1){
            //end B must be the node we come from and must be visited, so we set progenitor to end B
            progenitor = to_check->end_B;
            //if distance to the node we are checking is less than the distance map says, update it
            if(distance.at(progenitor) + to_check->weight < distance.at(to_check->end_A)){
                distance.at(to_check->end_A) = distance.at(progenitor) + to_check->weight;
                //also update its previous
                previous.at(to_check->end_A) = progenitor;
            }

            //add edge we just visited to the visited list
            visited_edges.push_back(to_check);

            //only queue the adjacent edes that arent checked and dont lead to a checked node
            //if it leads to a checked node, then we know we have already enqueued that edge when we processed that node 
            for(int i = 0; i < to_check->end_A->adjacent.size(); i++){
                bool is_valid_edge = true;
                //if either end A or B is a visited node, dont enqueue that adjacent edge
                if(std::find(visited_nodes.begin(), visited_nodes.end(), to_check->end_A->adjacent[i]->end_A) != visited_nodes.end()
                || std::find(visited_nodes.begin(), visited_nodes.end(), to_check->end_A->adjacent[i]->end_B) != visited_nodes.end()){
                    is_valid_edge = false;
                }

                if(std::count(visited_edges.begin(), visited_edges.end(), to_check->end_A->adjacent[i]) < 1 && is_valid_edge){
                    Q.push(to_check->end_A->adjacent[i]);
                }
            }

            //since we added all the edges of the node to the Q, the node is now visited
            visited_nodes.push_back(to_check->end_A);

        //else if end B is not a visited node, use it as the node to visit
        }else if(std::count(visited_nodes.begin(), visited_nodes.end(), to_check->end_B) < 1){
            //end A must be the node we come from and must be visited, so we set progenitor to end A
            progenitor = to_check->end_A;

            //if distance to the node we are checking is less than the distance map says, update it
            if(distance.at(progenitor) + to_check->weight < distance.at(to_check->end_B)){
                distance.at(to_check->end_B) = distance.at(progenitor) + to_check->weight;
                //also update its previous
                previous.at(to_check->end_B) = progenitor;
            }

            //add edge we just visited to the visited list
            visited_edges.push_back(to_check);

            //only queue the adjacent edes that arent checked and dont lead to a checked node
            //if it leads to a checked node, then we know we have already enqueued that edge when we processed that node
            for(int i = 0; i < to_check->end_B->adjacent.size(); i++){
                bool is_valid_edge = true;
                //if either end A or B is a visited node, dont enqueue that adjacent edge
                if(std::find(visited_nodes.begin(), visited_nodes.end(), to_check->end_B->adjacent[i]->end_A) != visited_nodes.end()
                || std::find(visited_nodes.begin(), visited_nodes.end(), to_check->end_B->adjacent[i]->end_B) != visited_nodes.end()){
                    is_valid_edge = false;
                }

                if(std::count(visited_edges.begin(), visited_edges.end(), to_check->end_B->adjacent[i]) < 1 && is_valid_edge){
                    Q.push(to_check->end_B->adjacent[i]);
                }
            }

            //since we added all the edges of the node to the Q, the node is now visited
            visited_nodes.push_back(to_check->end_B);

        }else{
            std::cout << "edge is irrelevent: " << to_check->weight << std::endl;
        }

        // std::cout << "in the while loop\n";

    }
    initialized = true;

}

//pass in the graph_nodes field of the Graph
void Graph::ShortPath::print(std::vector<Node *> total_nodes){
    std::cout << "shortest paths";

    //clean out nodes that werent used in Graph::ShortPath::dijkstras()
    std::vector<Node *> cleaned_nodes = total_nodes;
    for(int i = 0; i < total_nodes.size(); i++){
        if(cleaned_nodes[i]->adjacent.size() < 1){
            cleaned_nodes.erase(cleaned_nodes.begin() + i);
            i--;
        }
    }

    std::cout << "table of distances: \n";
    for(int i = 0; i < cleaned_nodes.size(); i++){
        std::cout << "Node ID: " << cleaned_nodes[i]->ID << " Distance: " << distance.at(cleaned_nodes[i]) << std::endl;
    }
    
    std::cout << "table of previous: \n";
    for(int k = 0; k < cleaned_nodes.size(); k++){
        if(previous.at(cleaned_nodes[k]) != nullptr){
            std::cout << "Node ID: " << cleaned_nodes[k]->ID << " Previous: " << previous.at(cleaned_nodes[k])->ID << std::endl;
        }else{
            std::cout << "Node ID: " << cleaned_nodes[k]->ID << " Previous: Nullptr" << std::endl;
        }
    }
}