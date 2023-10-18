#include "Tree.cpp"
using namespace std;
int main()
{

    BSTree t;
    t.Insert(t.root, 4);
    t.Insert(t.root, 2);
    t.Insert(t.root, 6);
    t.Insert(t.root, 14);
    t.Insert(t.root, 11);
    t.Insert(t.root, 13);
    cout << "\nINORDER = " << endl;
    t.inorder(t.root);
    cout << "\nPREORDER = " << endl;
    t.preorder(t.root);
    cout << "\nPOSTORDER = " << endl;
    t.postorder(t.root);
    cout << "HEIGHT = " << t.treeHeight(t.root) << endl;
    cout << "MAX = " << t.findMax() << endl;
    cout << "MIN = " << t.findMin() << endl;
    cout<<"NUM NODES = "<<t.treeNodeCount(t.root)<<endl;

}
