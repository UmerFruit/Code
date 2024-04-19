#include <iostream>
#include <queue>
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
    static int treeHeight(Node *&root)
    {
        if (!root)
        {
            return -1;
        }
        int RH = treeHeight(root->right);
        int LH = treeHeight(root->left);
        return 1 + (RH > LH ? RH : LH);
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
    void leaves(Node *root, int &count)
    {
        if (root == NULL)
            return;

        leaves(root->left, count);
        if (!root->left && !root->right)
            count++;
        leaves(root->right, count);
    }
    int findMax(Node *&root)
    {
        Node *temp = root;
        while (temp->right)
        {
            temp = temp->right;
        }
        return temp->data;
    }
    int findMin(Node* root)
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
    void BreadthFirst(Node *&root)
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        cout << endl;
    }
    Node *Delete(Node *&root, int data)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else if (root->data == data)
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            else if (root->left != NULL && root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else if (root->left == NULL && root->right != NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else
            {
                int max = findMax(root->left);
                root->data = max;
                root->left = Delete(root->left, max);
            }
        }
        else if (root->data > data)
        {
            root->left = Delete(root->left, data);
        }
        else
        {
            root->right = Delete(root->right, data);
        }
        return root;
    }
};
