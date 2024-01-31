

class Node
{
public:
    int data;
    int ID;
    Node *next;
    Node *previous;

    Node(/* args */);

    ~Node();
};

class Queue
{
public:
    Node *head;
    Node *tail;
    int length;

    Queue();

    int enqueue(Node*);

    int dequeue();

    void peek();
};