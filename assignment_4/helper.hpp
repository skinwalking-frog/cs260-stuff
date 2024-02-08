#pragma once

class Node
{
public:
    int data;
    Node *next;
    Node *last;
    int index;

    Node(int D = 0);

    ~Node();
};

class List
{
public:
    Node *start;
    Node *end;
    int length;

    List();

    void AddAtPos(int, int);

    int RemoveAtPos(int);

    int LookAtPos(int);

    void printlist();
};