#include "Headers.h"
#include <queue>
#include <stack>
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
class Tree
{
public:
    Node *root;
    void Build()
    {
        queue<int> q;
        int arr[] = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
        for (int i = 0; i < 13; i++)
        {
            q.push(arr[i]);
        }
        root = BuildTree(root);
    }
    Node *BuildTree(Node *root)
    {
        int d;
        cout<<"Enter Data for node"<<endl;
        cin>>d;
        root = new Node(d);
        if (d == -1)
        {
            return NULL;
        }
        cout << "Enter data for inserting in left of " << d << endl;
        root->left = BuildTree(root->left);
        cout << "Enter data for inserting in right of " << d << endl;
        root->right = BuildTree(root->right);

        return root;
    }
    Node *LOBuildTree(Node *root)
    {
        queue<Node *> q;
        int d;
        cout << "Enter Data for node: " << endl;
        cin >> d;
        root = new Node(d);
        q.push(root);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            cout << "Enter data for inserting in left of " << temp->data << endl;
            int l;
            cin >> l;
            if (l != -1)
            {
                temp->left = new Node(l);
                q.push(temp->left);
            }
            cout << "Enter data for inserting in right of " << temp->data << endl;
            int r;
            cin >> r;

            if (r != -1)
            {
                temp->right = new Node(r);
                q.push(temp->right);
            }
        }
        return root;
    }
    Tree()
    {
        root = NULL;
    }
    
    void LOBuild()
    {
        root = LOBuildTree(root);
    }
    void reverseLO()
    {
        queue<Node *> q;
        stack<Node *> s;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            s.push(temp);
            if (!temp)
            {
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
        while (!s.empty())
        {
            Node *temp = s.top();
            s.pop();
            if (!temp)
            {
                cout << endl;
            }
            else
            {
                cout << temp->data << " ";
            }
        }
        cout << endl;
    }
    void levelOrder()
    {
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (!temp)
            {
                cout << endl;
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                cout << temp->data << " ";
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
        cout << endl;
    }
    void Preorder()
    {
        // NLR
        preorder(root);
    }
    void preorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void Postorder()
    {
        // LRN
        postorder(root);
    }
    void postorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    void Inorder()
    {
        // LNR
        inorder(root);
    }
    void inorder(Node *root)
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
void leaves(Node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }
    leaves(root->left, count);
    if (!root->left && !root->right)
    {
        count++;
    }
    leaves(root->right, count);
}
// 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

int main()
{

}
