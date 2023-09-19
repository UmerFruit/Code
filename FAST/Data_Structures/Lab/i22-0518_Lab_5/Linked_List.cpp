#include "Student.cpp"
class Node
{
public:
    Student st;
    Node *next;
    Node *prev;
    Node(Student stud)
    {
        st = stud;
        next = NULL;
        prev = NULL;
    }
    ~Node()
    {
        next = NULL;
        prev = NULL;        
    }
};
ostream &operator<<(ostream &out, Node &lol)
{
    out << lol.st;
    return out;
}
class LinkedList
{
private:
    Node *head;
    Node *last;

public:
    Node &operator[](string id)
    {
        if (head == NULL)
        {
            cout << "EMPTY LIST!" << endl;
            return *head;
        }

        bool exists = false;
        Node *curr = head;
        Node *prev = head;
        while (curr->st.getid() != id && curr->next)
        {
            curr = curr->next;
        }
        if (curr == NULL)
        {
            cout << "Data not found :(" << endl;
            return *head;
        }
        return *curr;
    }
    Node &operator[](int idx)
    {
        if (head == NULL)
        {
            cout << "EMPTY LIST!" << endl;
            return *head;
        }
        int s = getSize();
        bool exists = false;
        Node *curr = head;
        Node *prev = head;
        int i = 0;
        while (i < idx && curr)
        {
            curr = curr->next;
            i++;
        }
        if (curr == NULL)
        {
            cout << "Data not found :(" << endl;
        }
        return *curr;
    }
    LinkedList(int ignore = 0)
    {
        head = NULL;
        last = NULL;
    }
    ~LinkedList()
    {

        while (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        delete head;
    }
    void insert(Student stud)
    {
        Node *temp = new Node(stud);

        if (head == NULL)
        {
            head = temp;
            last = temp;
        }
        else
        {
            Node *curr = head;

            while (curr->next != NULL)
            {
                curr = curr->next;
            }

            curr->next = temp;

            curr->next->prev = curr;

            last = curr->next;
        }
    }
    void remove(string id)
    {
        if (head == NULL)
        {
            cout << "EMPTY LIST!" << endl;
            return;
        }
        bool exists = false;
        Node *curr = head;
        while (curr->next != NULL)
        {
            if (curr->st.getid() == id)
            {
                exists = true;
                break;
            }
            curr = curr->next;
            if (curr->st.getid() == id)
            {
                exists = true;
                break;
            }
        }

        if (exists)
        {
            if (head == curr)
            {
                head = curr->next;
                head->prev = NULL;
                delete curr;
                return;
            }
            if (curr->next == NULL)
            {
                last = curr->prev;
                last->next = NULL;
                delete curr;
                return;
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
            curr->prev = NULL;
            curr->next = NULL;
        }
        else
        {
            cout << "Record not found :(" << endl;
        }
    }
    void printList()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->st << endl;
            temp = temp->next;
        }
    }
    void UpdateGPA(double cgpa, string id)
    {
        if (head == NULL)
        {
            cout << "empty" << endl;
            return;
        }
        Node &curr = (*this)[id];
        curr.st.setCGPA(cgpa);
    }
    void clear()
    {
        while (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        delete head;
        head = NULL;
    }
    bool isEmpty()
    {
        if (head == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int getSize()
    {
        int size = 0;
        Node *curr = head;
        while (curr)
        {
            curr = curr->next;
            size++;
        }
        return size;
    }
    // void sort()
    // {
    //     if (!head || !head->next)
    //     {
    //         return; // Nothing to sort
    //     }

    //     LinkedList sortedList; // Create a new linked list to hold the sorted elements

    //     while (head)
    //     {
    //         float maxGPA = head->st.getCGPA();
    //         Node *current = head;
    //         Node *prevMax = nullptr;

    //         // Find the element with the maximum GPA
    //         while (current->next)
    //         {
    //             if (current->next->st.getCGPA() > maxGPA)
    //             {
    //                 maxGPA = current->next->st.getCGPA();
    //                 prevMax = current;
    //             }
    //             current = current->next;
    //         }

    //         // Remove the element with the maximum GPA from the original list
    //         if (!prevMax)
    //         {
    //             head = head->next;
    //         }
    //         else
    //         {
    //             prevMax->next = prevMax->next->next;
    //         }

    //         // Insert the maximum GPA element into the sorted list
    //         sortedList.insert(current->st);
    //         delete current;
    //     }

    //     // Replace the original list with the sorted list
    //     head = sortedList.head;
    // }

    void sort()
    {
        int size = getSize();
        float gpa = 0;
        int idx = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size-i; j++)
            {
                if ((*this)[j].st.getCGPA() > gpa)
                {
                    idx = j;
                    gpa = (*this)[j].st.getCGPA();
                }
            }
            
            insert((*this)[idx].st);
            remove((*this)[idx].st.getid());
        }
    }
};
int main()
{
    Student e1;
    Student e2("9", "Humayun", 1, 5);
    Student e3("8", "Ali Faraz", 2, 20);
    Student e4("7", "Humayun", 4, 5);
    Student e5("6", "Ali Faraz", 6, 20);
   
    LinkedList LL;

    LL.insert(e2);
    LL.insert(e1);

    LL.insert(e3);
    LL.insert(e4);
    LL.insert(e5);
  
    int s = LL.getSize();
    cout<<"SIZE = "<<s<<endl;
    // for (int i = 0; i < s; i++)
    // {
    //     cout<<LL[i]<<endl;
    // }

    LL.sort();
    for (int i = 0; i < s; i++)
    {
        cout<<LL[i]<<endl;
    }
}