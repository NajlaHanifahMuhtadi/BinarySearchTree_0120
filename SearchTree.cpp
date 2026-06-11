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