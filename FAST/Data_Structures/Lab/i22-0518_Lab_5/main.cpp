#include "Linked_List.cpp"
int main()
{
    Student e1;
    Student e2("9", "Humayun", 2.9, 5);
    // Student e3("8", "Ali Faraz", 2.8, 20);
    // Student e4("7", "Humayun", 2.7, 5);
    // Student e5("6", "Ali Faraz", 2.6, 20);
    // Student e6("5", "Humayun", 2.5, 5);
    // Student e7("4", "Ali Faraz", 2.4, 20);
    // Student e8("3", "Ali Faraz", 2.3, 20);
    // Student e9("2", "Humayun", 2.2, 5);
    // Student e10("1", "Ali Faraz", 2.1, 20);

    LinkedList LL;

    LL.insert(e2);
    LL.insert(e1);

    // LL.insert(e3);
    // LL.insert(e4);
    // LL.insert(e5);
    // LL.insert(e6);
    // LL.insert(e7);
    // LL.insert(e8);
    // LL.insert(e9);
    // LL.insert(e10);
    int s = LL.getSize();
    // for (int i = 0; i < s; i++)
    // {
    //     cout<<LL[i]<<endl;
    // }

    // LL.printList();
    // LL.sort();
    // for (int i = 0; i < s; i++)
    // {
    //     cout<<LL[i]<<endl;
    // }
    // LL.printList();
}