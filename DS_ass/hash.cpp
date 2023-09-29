#include <iostream>
#include <cstring>
#include "sha1.hpp"
#include "Student.h"
using namespace std;
string hasher(string str)
{
    SHA1 checksum;
    checksum.update(str);
    string hash = checksum.final();
    return hash;
}
class hash_node
{
public:
    string prev_hash;
    string date;
    string time;
    string action;
    Student user;
    hash_node *next;
    hash_node *prev;

    hash_node(string prev_hash, string date, string time, string action, Student user)
    {
        this->prev_hash = prev_hash;
        this->date = date;
        this->time = time;
        this->action = action;
        this->user = user;
        this->next = NULL;
        this->prev = NULL;
    }
    string concat()
    {
        return prev_hash + date + time + action; //+whatever user.name or something;
    }
};
class hash_chain
{
    hash_node *head;
    hash_node *tail;

public:
    hash_chain()
    {
        head = NULL;
        tail = NULL;
    }
    void insert_end(string prev_hash, string date, string time, string action, Student user)
    {
        hash_node *temp = new hash_node(prev_hash, date, time, action, user);
        if (head == NULL && tail == NULL)
        {
            hash_node *temp = new hash_node(prev_hash, date, time, action, user);
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
    string hash()
    {
        return hasher(tail->concat());
    }
};
// code flow
int main()
{
    // Student T;
    // T.createstudent();
    // hash_chain H;
    // H.insert_end("\0", "\0", "\0", "\0", T);
    // H.insert(H.hash(), "\0", "\0", "\0", T);
    string input = "saif Ur Rehman";
    SHA1 checksum;
    checksum.update(input);
    const string hash = checksum.final();
    cout << "The SHA-1 of \"" << input << "\" is: " << hash << endl;
    return 0;

    return 0;
}
