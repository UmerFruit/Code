#include "Tree.cpp"
using namespace std;
bool FullBinaryTree(Node *);
bool PerfectBinaryTree(BSTree);
bool BalancedBinaryTree(Node *);
bool DegenerateTree(Node *);
int main()
{
    BSTree t;
    // t.Insert(t.root, 1);
    // t.Insert(t.root, 2);
    // t.Insert(t.root, 3);
    // t.Insert(t.root, 4);
    // t.Insert(t.root, -3);
    // t.Insert(t.root, 6);
    // t.Insert(t.root, 7);
    t.Insert(t.root, 50);
    t.Insert(t.root, 30);
    t.Insert(t.root, 80);
    t.Insert(t.root, 25);
    t.Insert(t.root, 40);
    t.Insert(t.root, 98);

    // cout << "\nINORDER = " << endl;
    // t.inorder(t.root);
    // cout << "\nPREORDER = " << endl;
    // t.preorder(t.root);
    // cout << "\nPOSTORDER = " << endl;
    // t.postorder(t.root);
    // cout << "\nHEIGHT = " << t.treeHeight(t.root) << endl;
    // cout << "MAX = " << t.findMax(t.root) << endl;
    // cout << "MIN = " << t.findMin(t.root) << endl;
    // cout << "NUM NODES = " << t.treeNodeCount(t.root) << endl;
    // cout<<"Breadth First = "<<endl; t.BreadthFirst(t.root);
    if (FullBinaryTree(t.root))
        cout << "FULL" << endl;
    else
        cout << "NOT FULL" << endl;
    if (PerfectBinaryTree(t))
        cout << "PERFECT" << endl;
    else
        cout << "NOT PERFECT" << endl;
    if (DegenerateTree(t.root))
        cout << "DEGENERATE" << endl;
    else
        cout << "NOT DEGENERATE" << endl;
    if (BalancedBinaryTree(t.root))
        cout << "BALANCED" << endl;
    else
        cout << "NOT BALANCED" << endl;
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
        return FullBinaryTree(root->left) && FullBinaryTree(root->right);

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
        int count = 0;
        t.leaves(t.root, count);
        int height = t.treeHeight(t.root);
        if (count == pow(2, height))
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
bool BalancedBinaryTree(Node *root)
{
    if (root == NULL)
        return true;

    int LH = BSTree::treeHeight(root->left);
    int RH = BSTree::treeHeight(root->right);
    bool Lcheck = BalancedBinaryTree(root->left), Rcheck = BalancedBinaryTree(root->right);
    if (abs(LH - RH) <= 1 && Lcheck && Rcheck)
        return true;

    return false;
}
bool DegenerateTree(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
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
        return DegenerateTree(root->right);
    }
    else
    {
        return false;
    }
}
