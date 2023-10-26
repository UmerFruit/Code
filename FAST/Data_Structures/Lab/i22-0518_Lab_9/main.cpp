#include "Tree.cpp"
using namespace std;
bool FullBinaryTree(Node *root);
bool PerfectBinaryTree(BSTree root);
bool BalancedBinaryTree(BSTree t);
bool DegenerateTree(Node *root);
int main()
{
    BSTree t;
    t.Insert(t.root, 10);
    t.Insert(t.root, 2);
    t.Insert(t.root, 11);
    t.Insert(t.root, 4);
    t.Insert(t.root, 5);
    t.Insert(t.root, 9);
    t.Insert(t.root, 7);

    // cout << "\nINORDER = " << endl;
    // t.inorder(t.root);
    // cout << "\nPREORDER = " << endl;
    // t.preorder(t.root);
    // cout << "\nPOSTORDER = " << endl;
    // t.postorder(t.root);
    // cout << "\nHEIGHT = " << t.treeHeight(t.root) << endl;
    // cout << "MAX = " << t.findMax(t.root) << endl;
    // cout << "MIN = " << t.findMin() << endl;
    // cout << "NUM NODES = " << t.treeNodeCount(t.root) << endl;
    // cout<<"Breadth First = "<<endl; t.BreadthFirst(t.root);
    // cout << (FullBinaryTree(t.root)? ) << endl;
    // cout<< PerfectBinaryTree(t)<<endl;
    cout << DegenerateTree(t.root) << endl;
}
bool FullBinaryTree(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    bool leaf = (root->left == NULL) && (root->right == NULL);
    bool full = (root->left != NULL) && (root->right != NULL);
    if (leaf)
        return true;

    if (full)
        return FullBinaryTree(root->left) || FullBinaryTree(root->right);

    return false;
}
bool PerfectBinaryTree(BSTree t)
{
    if (t.root == NULL)
    {
        return true;
    }
    if (FullBinaryTree(t.root))
    {
        if (t.treeNodeCount(t.root->left) == t.treeNodeCount(t.root->right))
        {
            return true;
        }
        else
            return false;
    }
    else
    {
        return false;
    }
}
bool balance(Node* root)
{
    if (t.root == NULL)
    {
        return true;
    }
    int LH = t.treeHeight(t.root);
    int RH = t.treeHeight(t.root);
    if ((LH - RH > -1) && (LH - RH < 1) && balance(t.root->left) && balance(t.root->right))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool BalancedBinaryTree(BSTree t)
{
    if (t.root == NULL)
    {
        return true;
    }
    return balance(t);
}
bool DegenerateTree(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    else
    {
        if (!root->right && !root->left)
        {
            return true;
        }
        if (root->left && !root->right)
        {
            return DegenerateTree(root->left);
        }
        else if (!root->left && root->right)
        {
            return DegenerateTree(root->left);
        }
        else
        {
            return false;
        }
    }
}