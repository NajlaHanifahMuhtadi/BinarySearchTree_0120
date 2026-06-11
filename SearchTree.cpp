#include <iostream>
#include <string>
using namespace std;

class Node 
{
public:
    string info;
    Node *leftChild;
    Node *rightChild;
    
    //constructor untuk node class
    Node(string i, Node *l, Node *r)
    {
        info = i;
        leftChild = l;
        rightChild = r;
    }
};

class BinaryTree 
{
public:
    Node *ROOT;
    
    BinaryTree()
    {
        ROOT = NULL; //Initializing ROOT to NULL
    }

    //insert a node in the binary search tree
    void insert(string element)
    {
        Node *newNode = new Node(element, NULL, NULL);
        
        newNode -> info = element;
        newNode -> leftChild = NULL;
        newNode -> rightChild = NULL;

        Node *parent = NULL;
        Node *currentNode = NULL;
    }
};