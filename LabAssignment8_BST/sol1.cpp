#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

// Function to create a new node
Node *createNode(int data)
{
    Node *t = new Node;
    t->data = data;
    t->left = t->right = NULL;
    return t;
}

// Preorder Traversal (Parent, Left, Right)
void Preorder(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " "; // Step 1: Visit Parent
        Preorder(p->left);      // Step 2: Visit Left Subtree
        Preorder(p->right);     // Step 3: Visit Right Subtree
    }
}

// Inorder Traversal (Left, Parent, Right)
void Inorder(Node *p)
{
    if (p != NULL)
    {
        Inorder(p->left);
        cout << p->data << " ";
        Inorder(p->right);
    }
}

// Postorder Traversal (Left, Right, Parent)
void Postorder(Node *p)
{
    if (p != NULL)
    {
        Postorder(p->left);
        Postorder(p->right);
        cout << p->data << " ";
    }
}

int main()
{
    // Creating nodes manually (Static Tree)
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    cout << "Preorder Traversal: ";
    Preorder(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    Inorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    Postorder(root);
    cout << endl;

    return 0;
}
