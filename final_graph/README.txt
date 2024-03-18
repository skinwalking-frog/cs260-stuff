compile either graph_main.cpp or graph_main_2.cpp with graph.cpp to run the respective main file.

required functionality:
    AddNode:
        graph.cpp - lines 37-44
    
    AddEdge:
        graph.cpp - lines 46-57

    minimum spanning tree:
        graph.cpp - lines 92-155

    Shortest path:
        graph.cpp - lines 178-342

Tests:
    graph_main.cpp and graph_main_2.cpp
        these tests test that the program executes without error, to determine if
        they give the correct result you will have to do a little bit of manual work
        (i've double checked that they do infact give correct answers, but you may want to see for yourself)

complexity analysis:
    AddNode - O(1) - we can only ever add 1 node at a time and its a constant time operation
    AddEdge - O(1) - same deal as the nodes
    minimum spanning tree - O(n) - has to visit every node once
    shortest path - somewhere around O(n^2) - we have to visit every node, and for each node visit every adjacent one.