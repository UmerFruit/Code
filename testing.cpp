#include "Headers.h"
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory free for node with data: " << val << endl;
    }
};
void insertatHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertatTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}
void insertatIndex(Node *&head, Node *&tail, int d, int idx)
{
    Node *insert = new Node(d);
    Node *curr = head;
    if (idx == 1)
    {
        insertatHead(head, d);
        return;
    }
    int i = 1;
    while (i < idx - 1)
    {
        curr = curr->next;
        i++;
    }
    if (!curr->next)
    {
        insertatTail(tail, d);
        return;
    }
    insert->next = curr->next;
    curr->next = insert;
}
void printList(Node *&head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void Deletenode(Node *&head,Node *&tail, int position)
{

    if (position == 1)
    {
        Node *prev = head;
        head = head->next;
        prev->next = NULL;
        delete prev;
        return;
    }
    Node *curr = head;
    Node *prev = NULL;

    int i = 1;
    while (i < position)
    {
        prev = curr;
        curr = curr->next;
        i++;
    }
    if(curr->next == NULL)
    {
        tail = prev;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertatHead(head, 12);
    insertatHead(head, 15);
    insertatTail(tail, 19);
    insertatTail(tail, 20);
    insertatIndex(head, tail, 99, 2);
    printList(head);
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    Deletenode(head,tail, 3);
    printList(head);
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl; 
}