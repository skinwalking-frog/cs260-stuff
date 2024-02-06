#pragma once

class Node
{
public:
    int data;
    Node *next;
    Node *previous;

    Node(int);

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

int test();