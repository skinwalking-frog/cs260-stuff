

class Node {
    
    public:
    
    Node(int value);
    int data;
    Node* left;
    Node* right;
};

class BinaryTree {

    Node* Add_parent_search(int search_value, Node* start);

    Node* Find_replacement(int value, Node* start);

    Node* Get_parent(int value, Node* start);

    public:

    //needs to be public for recursive methods to work as implemented currently
    Node* root;

    BinaryTree();

    void Add(int);

    void Remove(int);

    bool Search(int, Node*);

    void Display_in_order(Node* start);

    void Display_Tree(Node* start);
};