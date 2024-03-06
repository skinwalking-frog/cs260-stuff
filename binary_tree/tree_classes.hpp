

class Node {
    
    public:
    
    Node(int value);
    int data;
    Node* left;
    Node* right;

    ~Node();
};

class BinaryTree {

    Node* Add_parent_search(int search_value, Node* start);

    Node* Find_replacement(int value, Node* start);

    Node* Get_parent(int value, Node* start);

    void Delete_tree(Node* node);

    public:

    //needs to be public for recursive methods to work as implemented currently
    Node* root;

    BinaryTree();

    ~BinaryTree();

    void Add(int);

    void Remove(int);

    bool Search(int, Node*);

    void Display_in_order(Node* start);

    void Display_Tree(Node* start);
};