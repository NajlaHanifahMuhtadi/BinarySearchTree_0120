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

        search(element, parent, currentNode);

        if (element < parent -> info)
        {
            parent -> leftChild = newNode;
        }
        else if (element > parent -> info)
        {
            parent -> rightChild = newNode;
        }
    }

    //this function searches the current node of the specified node
    //as well as the current node of its parent
    void search(string element, Node *&parent, Node *&currentNode)
    {
        currentNode = ROOT;
        parent = NULL;

        while (currentNode != NULL && currentNode -> info != element)
        {
            parent = currentNode;

            if (element < currentNode -> info)
                currentNode = currentNode -> leftChild;
            else
                currentNode = currentNode -> rightChild;
        }
    }

    void inorder (Node *ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != NULL)
        {
            inorder(ptr -> leftChild);
            cout << ptr -> info << " ";
            inorder(ptr -> rightChild);
        }
    }
};