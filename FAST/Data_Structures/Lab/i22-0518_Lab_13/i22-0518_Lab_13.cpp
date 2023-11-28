#include <iostream>
#include <vector>
using namespace std;
class Student
{
public:
    string name, house;
    int abilities, bravery, cunning, intelligence, loyalty;
    Student(string n, int a, int b, int c, int i, int l)
    {
        name = n;
        abilities = a;
        bravery = b;
        cunning = c;
        intelligence = i;
        loyalty = l;
    }
    void sethouse(string h) { house = h; };

    void print()
    {
        cout << "Abilities: " << abilities << endl;
        cout << "Bravery: " << bravery << endl;
        cout << "Cunning" << cunning << endl;
        cout << "Intelligence" << intelligence << endl;
        cout << "Loyalty" << loyalty << endl;
    }
};
class Node
{
public:
    string data;
    Node *next;
    Node(string s)
    {
        this->data = s;
        this->next = NULL;
    }
};
class AdjList
{
public:
    Node *head;
    AdjList()
    {
        head = NULL;
    }
    void insert(string data)
    {
        if (head == NULL)
        {
            head = new Node(data);
        }
        else
        {
            Node *temp = new Node(data);
            Node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = temp;
        }
    }
    void Display()
    {
        for (Node *curr = head; curr != NULL; curr = curr->next)
        {
            cout << curr->data;
            curr == head ? cout << ": " : cout << " ";
        }
        cout << endl;
    }
};
class Graph
{
public:
    vector<AdjList> list;
    int vert;
    Graph(vector<Student> s)
    {
        vert = s.size();

        for (int i = 0; i < vert; i++)
        {
            list.push_back(AdjList());
            list[i].insert(s[i].name);
        }
    }
    void addvert(Student &l)
    {
        list.push_back(AdjList());
        list[list.size() - 1].insert(l.name);
        vert++;
    }
    void insertEdge(string src, string dest)
    {
        int sidx;
        int didx;

        for (int i = 0; i < vert; i++)
        {
            if (list[i].head->data == src)
                sidx = i;

            if (list[i].head->data == dest)
                didx = i;
        }
        list[sidx].insert(dest);
        list[didx].insert(src);
    }
    void showGraphStrct()
    {
        cout << "Graph: " << endl;
        for (int i = 0; i < vert; i++)
            list[i].Display();
    }

    ~Graph()
    {
    }
};
void sortingHat(vector<Student> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if ((v[i].bravery > v[i].cunning || v[i].bravery > v[i].abilities || v[i].bravery > v[i].intelligence) && (v[i].loyalty > v[i].cunning || v[i].loyalty > v[i].abilities || v[i].loyalty > v[i].intelligence))
        {
            v[i].sethouse("Gryffindor");
        }
        else if ((v[i].loyalty > v[i].cunning || v[i].loyalty > v[i].bravery || v[i].loyalty > v[i].intelligence) && (v[i].abilities > v[i].bravery || v[i].abilities > v[i].cunning || v[i].abilities > v[i].intelligence))
        {
            v[i].sethouse("Hufflepuff");
        }
        else if ((v[i].intelligence > v[i].cunning || v[i].intelligence > v[i].bravery || v[i].intelligence > v[i].loyalty) && (v[i].abilities > v[i].cunning || v[i].abilities > v[i].bravery || v[i].abilities > v[i].abilities > v[i].loyalty))
        {
            v[i].sethouse("Ravenclaw");
        }
        else if ((v[i].cunning > v[i].bravery || v[i].cunning > v[i].loyalty || v[i].cunning > v[i].intelligence) && (v[i].abilities > v[i].bravery || v[i].abilities > v[i].loyalty || v[i].abilities > v[i].intelligence))
        {
            v[i].sethouse("Slytherin");
        }
        else
        {
            v[i].sethouse("Lawaris bacha");
        }
    }
}
int main()
{
    vector<Student> students;
    students.push_back(Student("Harry", 8, 9, 7, 8, 5));
    students.push_back(Student("Ron", 7, 8, 6, 7, 4));
    students.push_back(Student("Hermione", 9, 10, 10, 9, 7));
    students.push_back(Student("Draco", 6, 7, 8, 5, 9));
    Student s("Saif", 5, 2, 1, 4, 7);
    Graph g(students);
    g.insertEdge("Harry", "Ron");
    g.insertEdge("Harry", "Hermione");
    g.insertEdge("Ron", "Hermione");
    g.insertEdge("Draco", "Harry");
    g.addvert(s);
    students.push_back(s);
    g.insertEdge("Saif", "Harry");
    sortingHat(students);
    g.showGraphStrct();
    for (int i = 0; i < students.size(); i++)
    {
        cout << students[i].name << ": " << students[i].house << endl;
    }
}