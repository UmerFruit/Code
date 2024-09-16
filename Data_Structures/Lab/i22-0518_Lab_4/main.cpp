#include "Linked_List.cpp"
int main()
{
    Employee e1;
    Employee e2(5, "Humayun", "987654321", 9999, 6666);
    Employee e3(9, "Ali Faraz", "728935789", 555, 444);

    LinkedList LL;
    
    LL.insert(e1);
    LL.insert(e2);
    LL.insert(e3);
    LL.remove(5);
    LL.printList();
}