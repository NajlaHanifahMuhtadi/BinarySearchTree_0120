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

        if (parent == NULL)
        {
            ROOT = newNode;
            return;
        }

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

    void preorder (Node *ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != NULL)
        {
            cout << ptr -> info << " ";
            preorder(ptr -> leftChild);
            preorder(ptr -> rightChild);
        }
    }

    void postorder (Node *ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != NULL)
        {
            postorder(ptr -> leftChild);
            postorder(ptr -> rightChild);
            cout << ptr -> info << " ";
        }
    }
};

int main()
{
    BinaryTree obj;

    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform Inorder traversal" << endl;
        cout << "3. Perform Preorder traversal" << endl;
        cout << "4. Perform Postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: (1-5): ";

        char ch;
        cin >> ch;

        cout << endl;

        switch (ch)
        {
            case '1':
            {
                cout << "Enter a word: ";
                string word;
                cin >> word;
                obj.insert(word);
                break;
            }
            case '2':
            {
                obj.inorder(obj.ROOT);
                break;
            }
            case '3':
            {
                obj.preorder(obj.ROOT);
                break;
            }
            case '4':
            {
                obj.postorder(obj.ROOT);
                break;
            }
            case '5':
            {
                return 0;
            }
            default:
            {
                cout << "Invalid option" << endl;
                break;
            }
        }
    }
}