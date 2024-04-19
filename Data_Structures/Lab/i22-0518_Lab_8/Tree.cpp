#include <iostream>
using namespace std;
class Node
{
public:
    Node *left, *right;
    int data;
    Node(int d) : data(d), left(NULL), right(NULL) {}
    ~Node() { left = NULL, right = NULL; }
};
class BSTree
{
public:
    Node *root;
    BSTree()
    {
        root = NULL;
    }
    ~BSTree()
    {
        deleteALL(root);
    }
    void deleteALL(Node *&root)
    {
        if (root == NULL)
        {
            return;
        }
        deleteALL(root->left);
        deleteALL(root->right);
        delete root;
    }
    int treeHeight(Node *&root)
    {
        if (!root)
        {
            return -1;
        }
        int RH = treeHeight(root->right);
        int LH = treeHeight(root->left);
        return 1 + (RH>LH? RH : LH);
    }
    void Insert(Node *&root, int data)
    {
        Node *&curr = root;
        if (curr == NULL)
        {
            curr = new Node(data);
        }
        else if (data > curr->data)
        {
            // right ki call recursion
            Insert(curr->right, data);
        }
        else if (data < curr->data)
        {
            // left ki call recursion
            Insert(curr->left, data);
        }
    }
    bool Search(Node *&root, int key)
    {
        if (root == NULL)
        {
            return 0;
        }
        else if (root->data == key)
        {
            return 1;
        }
        return Search(root->left, key) || Search(root->right, key);
    }
    void inorder(Node *&root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    void postorder(Node *&root)
    {
        if (root == NULL)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    void preorder(Node *&root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    int findMax()
    {
        Node *temp = root;
        while (temp->right)
        {
            temp = temp->right;
        }
        return temp->data;
    }
    int findMin()
    {
        Node *temp = root;
        while (temp->left)
        {
            temp = temp->left;
        }
        return temp->data;
    }
    int treeNodeCount(Node *&root)
    {
        if (root == NULL)
            return 0;
        
        return treeNodeCount(root->left) + treeNodeCount(root->right) + 1;
    }
    bool isEmpty()
    {
        return !root;
    }
    
};
