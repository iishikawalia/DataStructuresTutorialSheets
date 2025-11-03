#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

Node *root = NULL;

// Function to create a new node
Node *createNode(int key)
{
    Node *t = new Node;
    t->data = key;
    t->left = t->right = NULL;
    return t;
}

// INSERTION
Node *Insert(Node *p, int key)
{
    Node *t = NULL;

    if (p == NULL)
    {
        t = createNode(key);
        return t;
    }

    if (key < p->data)
        p->left = Insert(p->left, key);
    else if (key > p->data)
        p->right = Insert(p->right, key);
    else
        cout << "Duplicate key not allowed: " << key << endl;

    return p;
}

// INORDER TRAVERSAL
void Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->left);
        cout << p->data << " ";
        Inorder(p->right);
    }
}

// FIND MINIMUM NODE
Node *findMin(Node *p)
{
    while (p && p->left != NULL)
        p = p->left;
    return p;
}

// DELETE NODE
Node *Delete(Node *p, int key)
{
    if (p == NULL)
        return NULL;

    if (key < p->data)
        p->left = Delete(p->left, key);
    else if (key > p->data)
        p->right = Delete(p->right, key);
    else
    {
        // Node found
        // No child found
        if (p->left == NULL && p->right == NULL)
        {
            delete p;
            return NULL;
        }
        // One child - left sub-tree doesn't exist
        else if (p->left == NULL)
        {
            Node *temp = p->right;
            delete p;
            return temp;
        }
        // One child - right sub-tree doesn't exist
        else if (p->right == NULL)
        {
            Node *temp = p->left;
            delete p;
            return temp;
        }
        else
        {
            // Node has two children
            Node *succ = findMin(p->right);
            p->data = succ->data;
            p->right = Delete(p->right, succ->data);
        }
    }
    return p;
}

// MAXIMUM DEPTH
int maxDepth(Node *p)
{
    if (p == NULL)
        return 0;
    int lDepth = maxDepth(p->left);
    int rDepth = maxDepth(p->right);
    return max(lDepth, rDepth) + 1;
}

// MINIMUM DEPTH
int minDepth(Node *p)
{
    if (p == NULL)
        return 0;
    int lDepth = minDepth(p->left);
    int rDepth = minDepth(p->right);

    // If one child is NULL, we must go through the non-null child
    if (p->left == NULL)
        return rDepth + 1;
    if (p->right == NULL)
        return lDepth + 1;

    return min(lDepth, rDepth) + 1;
}

int main()
{
    root = Insert(root, 50);
    Insert(root, 30);
    Insert(root, 70);
    Insert(root, 20);
    Insert(root, 40);
    Insert(root, 60);
    Insert(root, 80);

    cout << "Inorder traversal of BST: ";
    Inorder(root);
    cout << endl;

    cout << "Deleting 20..." << endl;
    root = Delete(root, 20);
    Inorder(root);
    cout << endl;

    cout << "Deleting 30..." << endl;
    root = Delete(root, 30);
    Inorder(root);
    cout << endl;

    cout << "Deleting 50..." << endl;
    root = Delete(root, 50);
    Inorder(root);
    cout << endl;

    cout << endl
         << "Maximum depth of BST: " << maxDepth(root) << endl;
    cout << endl
         << "Minimum depth of BST: " << minDepth(root) << endl;

    return 0;
}
