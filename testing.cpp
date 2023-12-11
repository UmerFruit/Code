#include "Headers.h"
using namespace std;
class node
{
public:
   int data;
   node *next;
   node(int data = 0)
   {
      this->data = data;
      next = NULL;
   }
};
void print(node *head)
{
   node *temp = head;
   while (temp != NULL)
   {
      cout << temp->data << " ";
      temp = temp->next;
   }
   cout << endl;
}
int main()
{
   node *head = new node(5);
   head->next = new node(6);
   head->next->next = new node(3);
   print(head);
}
