

class Node {
    
    public:
    
    Node(int);
    int data;
    Node* left;
    Node* right;
};

class BinaryTree {
    Node* root;

    Node* rec_parent_search(int, Node*);

    public:

    void Add(int);

    void Remove(int);

    bool Search(int, Node*);

    void Display();
};