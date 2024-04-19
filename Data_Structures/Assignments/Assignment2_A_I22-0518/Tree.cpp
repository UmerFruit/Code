#include "Queue.cpp"
using namespace std;
template <class T>
class BSTNode
{
public:
    BSTNode<T> *left, *right;
    T data;
    BSTNode(T d) : data(d), left(NULL), right(NULL) {}
    ~BSTNode() { left = NULL, right = NULL; }
};
template <class T>
class BSTree
{
public:
    BSTNode<T> *root;
    BSTree()
    {
        root = NULL;
    }
    void Insert(T data)
    {
        Ins(root, data);
    }
    bool Search(T key)
    {
        return search(root, key);
    }
    void Inorder()
    {
        inorder(root);
    }
  
    T findMax()
    {
        BSTNode<T> *temp = root;
        while (temp->right)
        {
            temp = temp->right;
        }
        return temp->data;
    }
   
    T findMin()
    {
        BSTNode<T> *temp = root;
        while (temp->left)
        {
            temp = temp->left;
        }
        return temp->data;
    }
    bool isEmpty()
    {
        return root;
    }
private:
   

   
    BSTNode<T> *Ins(BSTNode<T> *&root, T data)
    {
        if (root == NULL)
        {
            root = new BSTNode<T>(data);
            return root;
        }
        else if (data > root->data)
        {
            // right ki call recursion
            root->right = Ins(root->right, data);
        }
        else if (data < root->data)
        {
            // left ki call recursion
            root->left = Ins(root->left, data);
        }
        return root;
    }
    bool search(BSTNode<T> *&root, T key)
    {
        if (root == NULL)
        {
            return 0;
        }
        else if (root->data == key)
        {
            return 1;
        }
        return search(root->left, key) || search(root->right, key);
    }
    void inorder(BSTNode<T> *&root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }  
};
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
        root = insert(root, x);
    }
    
    AVLNode<T> *Search(T x)
    {
        return search(root, x);
    }
    void Inorder()
    {
        inorder(root);
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

    void inorder(AVLNode<T> *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }

    AVLNode<T> *insert(AVLNode<T> *root, T x)
    {
        if (root == NULL)
        {
            n += 1;
            AVLNode<T> *temp = new AVLNode<T>(x);
            return temp;
        }
        if (x < root->key)
            root->left = insert(root->left, x);
        else if (x > root->key)
            root->right = insert(root->right, x);
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

    AVLNode<T> *search(AVLNode<T> *root, T x)
    {
        if (root == NULL)
            return NULL;
        T k = root->key;
        if (k == x)
            return root;
        else if (k > x)
            return search(root->left, x);
        else
            return search(root->right, x);
    }
};
