#include <iostream>
#include "Queue.cpp"
using namespace std;
template <typename T>
class AVLNode
{
public:
    T key;
    int height;
    AVLNode<T> *left;
    AVLNode<T> *right;
    AVLNode(T k)
    {
        height = 1;
        key = k;
        left = NULL;
        right = NULL;
    }
};
template <typename T>
class AVL
{
public:
    AVLNode<T> *root;
    int n;
    AVL()
    {
        root = NULL;
    }
    void Insert(T x)
    {
        root = insertUtil(root, x);
    }
    void deleteNode(T x)
    {
        root = removeUtil(root, x);
    }
    AVLNode<T> *Search(T x)
    {
        return searchUtil(root, x);
    }
    void Inorder()
    {
        inorderUtil(root);
        cout << endl;
    }
    void levelOrder()
    {
        Queue<AVLNode<T> *> q;
        q.Enqueue(root);
        q.Enqueue(NULL);
        while (!q.isEmpty())
        {
            AVLNode<T> *temp = q.FRONT();
            q.Dequeue();
            if (!temp)
            {
                cout << endl;
                if (!q.isEmpty())
                {
                    q.Enqueue(NULL);
                }
            }
            else
            {
                cout << temp->key << " ";
                if (temp->left)
                {
                    q.Enqueue(temp->left);
                }
                if (temp->right)
                {
                    q.Enqueue(temp->right);
                }
            }
        }
        cout << endl;
    }

private:
    int height(AVLNode<T> *root)
    {
        if (root == NULL)
            return 0;
        return root->height;
    }
    AVLNode<T> *rightRotation(AVLNode<T> *root)
    {
        AVLNode<T> *newhead = root->left;
        root->left = newhead->right;
        newhead->right = root;
        root->height = 1 + max(height(root->left), height(root->right));
        newhead->height = 1 + max(height(newhead->left), height(newhead->right));
        return newhead;
    }

    AVLNode<T> *leftRotation(AVLNode<T> *root)
    {
        AVLNode<T> *newhead = root->right;
        root->right = newhead->left;
        newhead->left = root;
        root->height = 1 + max(height(root->left), height(root->right));
        newhead->height = 1 + max(height(newhead->left), height(newhead->right));
        return newhead;
    }

    void inorderUtil(AVLNode<T> *root)
    {
        if (root == NULL)
            return;
        inorderUtil(root->left);
        cout << root->key << " ";
        inorderUtil(root->right);
    }

    AVLNode<T> *insertUtil(AVLNode<T> *root, T x)
    {
        if (root == NULL)
        {
            n += 1;
            AVLNode<T> *temp = new AVLNode<T>(x);
            return temp;
        }
        if (x < root->key)
            root->left = insertUtil(root->left, x);
        else if (x > root->key)
            root->right = insertUtil(root->right, x);
        root->height = 1 + max(height(root->left), height(root->right));
        int bal = height(root->left) - height(root->right);
        if (bal > 1)
        {
            if (x < root->left->key)
            {
                return rightRotation(root);
            }
            else
            {
                root->left = leftRotation(root->left);
                return rightRotation(root);
            }
        }
        else if (bal < -1)
        {
            if (x > root->right->key)
            {
                return leftRotation(root);
            }
            else
            {
                root->right = rightRotation(root->right);
                return leftRotation(root);
            }
        }
        return root;
    }

    AVLNode<T> *removeUtil(AVLNode<T> *root, T x)
    {
        if (root == NULL)
            return NULL;
        if (x < root->key)
        {
            root->left = removeUtil(root->left, x);
        }
        else if (x > root->key)
        {
            root->right = removeUtil(root->right, x);
        }
        else
        {
            AVLNode<T> *r = root->right;
            if (root->right == NULL)
            {
                AVLNode<T> *l = root->left;
                delete (root);
                root = l;
            }
            else if (root->left == NULL)
            {
                delete (root);
                root = r;
            }
            else
            {
                while (r->left != NULL)
                    r = r->left;
                root->key = r->key;
                root->right = removeUtil(root->right, r->key);
            }
        }
        if (root == NULL)
            return root;
        root->height = 1 + max(height(root->left), height(root->right));
        int bal = height(root->left) - height(root->right);
        if (bal > 1)
        {
            if (height(root->left) >= height(root->right))
            {
                return rightRotation(root);
            }
            else
            {
                root->left = leftRotation(root->left);
                return rightRotation(root);
            }
        }
        else if (bal < -1)
        {
            if (height(root->right) >= height(root->left))
            {
                return leftRotation(root);
            }
            else
            {
                root->right = rightRotation(root->right);
                return leftRotation(root);
            }
        }
        return root;
    }
    AVLNode<T> *searchUtil(AVLNode<T> *root, T x)
    {
        if (root == NULL)
            return NULL;
        T k = root->key;
        if (k == x)
            return root;
        if (k > x)
            return searchUtil(root->left, x);
        if (k < x)
            return searchUtil(root->right, x);
    }
};


