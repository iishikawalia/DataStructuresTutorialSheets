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
Node* createNode(int data)
{
    Node *t = new Node;
    t->data = data;
    t->left = t->right = NULL;
    return t;
}

// Function to insert new nodes into BST (recursive)
Node* insert(Node *root, int key)
{
    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

// (a) Search - Recursive
Node* RSearch(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (key == root->data)
        return root;
    else if (key < root->data)
        return RSearch(root->left, key);
    else
        return RSearch(root->right, key);
}

// (a) Search - Non Recursive
Node* Search(Node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

// (b) Maximum Element
Node* MaxNode(Node *root)
{
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

// (c) Minimum Element
Node* MinNode(Node *root)
{
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

// (d) Inorder Successor
Node* InorderSuccessor(Node *root, Node *x)
{
    Node *succ = NULL;

    while (root != NULL)
    {
        if (x->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (x->data > root->data)
            root = root->right;
        else
            break;
    }
    return succ;
}

// (e) Inorder Predecessor
Node* InorderPredecessor(Node *root, Node *x)
{
    Node *pred = NULL;

    while (root != NULL)
    {
        if (x->data > root->data)
        {
            pred = root;
            root = root->right;
        }
        else if (x->data < root->data)
            root = root->left;
        else
            break;
    }
    return pred;
}

// Inorder traversal (to display the tree)
void Inorder(Node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder Traversal of BST: ";
    Inorder(root);
    cout << endl;

    // (a) Searching
    int key = 60;
    Node *found = RSearch(root, key);
    if (found)
        cout << "Recursive Search: " << key << " found" << endl;
    else
        cout << "Recursive Search: " << key << " not found" << endl;

    found = Search(root, key);
    if (found)
        cout << "Non-Recursive Search: " << key << " found" << endl;
    else
        cout << "Non-Recursive Search: " << key << " not found" << endl;

    // (b) Maximum element
    cout << "Maximum Element: " << MaxNode(root)->data << endl;

    // (c) Minimum element
    cout << "Minimum Element: " << MinNode(root)->data << endl;

    // (d) Inorder Successor and (e) Predecessor
    Node *x = RSearch(root, 30);
    Node *succ = InorderSuccessor(root, x);
    Node *pred = InorderPredecessor(root, x);

    if (succ)
        cout << "Inorder Successor of " << x->data << " is " << succ->data << endl;
    else
        cout << "Inorder Successor of " << x->data << " doesn't exist" << endl;

    if (pred)
        cout << "Inorder Predecessor of " << x->data << " is " << pred->data << endl;
    else
        cout << "Inorder Predecessor of " << x->data << " doesn't exist" << endl;

    return 0;
}
