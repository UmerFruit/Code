#ifndef LOGGING_H_
#define LOGGING_H_

#include "Headers.h"
string getTimestamp()
{
    time_t now = time(0);
    string timestamp = ctime(&now);
    return timestamp;
}
void replaceCharInString(string &str, char oldChar, char newChar)
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (str[i] == oldChar)
        {
            str[i] = newChar;
        }
    }
}
class st
{
public:
    string log;
    string timestamp;
    string prev_hash;

    st()
    {
        prev_hash = "";
        log = "";
        timestamp = "";
    }
};

class Hash_node
{
public:
    st data;
    Hash_node *next;
    Hash_node *prev;

    Hash_node(string log)
    {
        replaceCharInString(log, ' ', '_');
        replaceCharInString(log, ':', '.');
        data.log = log;
        string t = getTimestamp();
        t.pop_back();
        replaceCharInString(t, ' ', '_');
        replaceCharInString(t, ':', '.');
        data.timestamp = t;
        this->next = NULL;
        this->prev = NULL;
    }
    Hash_node(st &da)
    {

        data.prev_hash = da.prev_hash;
        data.log = da.log;
        data.timestamp = da.timestamp;
        this->next = NULL;
        this->prev = NULL;
    }
    string inputHash()
    {
        string hashinput = data.log + data.prev_hash;
        return hashinput;
    }
    void print()
    {
        cout << "\ndata.prev_hash: " << data.prev_hash << endl;
        cout << "data.log: " << data.log << endl;
        cout << "TimeStamp: " << data.timestamp << endl
             << endl;
    }
    bool operator==(Hash_node &h)
    {
        return (!(data.log.compare(h.data.log)) && next == h.next && prev == h.prev);
    }
};
class Hash_chain
{
public:
    Hash_node *head;
    Hash_node *tail;

public:
    Hash_chain()
    {
        head = NULL;
        tail = NULL;
    }
    void AddBlock(string timestamp, string action, string user, string position, bool s)
    {
        string log = concat(timestamp, action, user, position, s);
        Hash_node *temp = new Hash_node(log);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            Hash_node *curr = head;

            while (curr->next != NULL)
            {
                curr = curr->next;
            }

            curr->next = temp;

            curr->next->prev = curr;

            tail = temp;
        }
        if (tail->prev != NULL)
            tail->data.prev_hash = Generatehash(tail->prev->inputHash());
        else
            temp->data.prev_hash = ".";
    }

    string concat(string timestamp, string action, string user, string position, bool s)
    {
        timestamp.pop_back();
        string success;
        s ? success = "Done Successfully" : success = "Unsuccessful";
        string cat = "Timestamp: " + timestamp + " " + "User: " + user + " " + position + " " + "Action: " + action + " " + success;
        return cat;
    }
    void printList()
    {
        if (head == NULL)
        {
            return;
        }
        int i = 1;
        Hash_node *curr = head;
        while (curr != NULL)
        {
            cout << "LOG# " << i++ << endl;
            curr->print();
            curr = curr->next;
        }
    }
    void recalulcateChain()
    {
        int idx = checkChainConsistency();
        if (idx != -1)
        {
            Hash_node *curr = head->next;
            while (curr != NULL)
            {
                curr->data.prev_hash = Generatehash(curr->prev->inputHash());
                curr = curr->next;
            }
        }
    }
    string Generatehash(string str)
    {
        SHA1 checksum;
        checksum.update(str);
        string hash = checksum.final();
        return hash;
    }
    // void restoreBlock();

    void injectDataInChain(int InjectIndex, string InjectData)
    {
        if (head == NULL)
            return;

        Hash_node *curr = head;
        int i = 1;
        while (i < InjectIndex && curr)
        {
            curr = curr->next;
            i++;
        }
        if (curr == NULL)
            cout << "Index not found" << endl;
        curr->data.log = InjectData;
    }

    int checkChainConsistency()
    {
        if (head == NULL)
        {
            cout << "Empty Chain" << endl;
            return -1;
        }
        head->next->prev = head; 
        Hash_node *curr = head->next;
        while (curr != NULL)
        {
            if (curr->data.prev_hash != Generatehash(curr->prev->inputHash()))
            {
                cout << "Current Node:\n\n";
                curr->print();

                cout << "Previous 2 Nodes:\n\n";
                if (curr->prev)
                {
                    curr->prev->print();

                    if (curr->prev->prev)
                    {
                        curr->prev->prev->print();
                    }
                }
                cout << "Next 2 Nodes:\n\n";
                if (curr->next)
                {
                    curr->next->print();

                    if (curr->next->next)
                    {
                        curr->next->next->print();
                    }
                }
                return FindBlock(curr);
            }
            curr = curr->next;
        }

        return -1;
    }

    int Size()
    {
        int size = 0;
        Hash_node *curr = head;
        while (curr != NULL)
        {
            curr = curr->next;
            size++;
        }
        return size;
    }
    void RemoveBlock(int position)
    {
        if (head == NULL)
        {
            cout << "EMPTY LIST!" << endl;
            return;
        }
        else if (position < 0 || position > Size())
        {
            cout << "Index not found" << endl;
            return;
        }
        if (position == 1)
        {
            Hash_node *prev = head;
            head = head->next;
            prev->next = NULL;
            delete prev;
            return;
        }
        Hash_node *curr = head;
        int i = 1;
        while (i < position)
        {
            curr = curr->next;
            i++;
        }
        curr->prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
    void writeChain()
    {
        ofstream fout;
        string time = getTimestamp();
        time.pop_back();
        replaceCharInString(time, ' ', '_');
        replaceCharInString(time, ':', '.');
        Hash_node *curr = head;
        fout.open("Hashlogs/HASHCHAIN_<" + time + ">.txt");
        if (!fout)
        {
            cout << "Not opened" << endl;
            return;
        }
        int i = 0;
        while (curr)
        {
            size_t s1 = curr->data.log.size();
            size_t s2 = curr->data.prev_hash.size();
            size_t s3 = curr->data.timestamp.size();
            fout << curr->data.log << endl;
            fout << curr->data.prev_hash << endl;
            fout << curr->data.timestamp << endl;
            curr = curr->next;
        }
        fout.close();
    }
    void readChain()
    {
        ifstream fin;
        fin.open("Hashlogs/HASHCHAIN_<Sun_Oct__1_00.20.56_2023>.txt");
        if (!fin)
        {
            cout << "File doesnt exist" << endl;
            return;
        }
        st test;
        fin >> test.log;
        fin >> test.prev_hash;
        fin >> test.timestamp;
        this->head = new Hash_node(test);
        Hash_node *curr = this->head;

        while (!fin.eof()) 
        {
            fin >> test.log;
            fin >> test.prev_hash;
            fin >> test.timestamp;
            curr->next = new Hash_node(test);
            curr = curr->next;
        }
        fin.close();
    }
    int FindBlock(Hash_node *data)
    {
        if (head == NULL)
        {
            cout << "EMPTY LIST!" << endl;
            return -1;
        }
        int idx, i = 0;

        bool exists = false;
        Hash_node *curr = head;
        while (curr != NULL)
        {
            if (curr == data)
            {
                idx = i;
                exists = true;
                break;
            }
            curr = curr->next;
            i++;
        }

        if (exists)
        {
            return idx;
        }
        else
        {
            cout << "Data not found :(" << endl;
            return -1;
        }
    }
};
class LogManager
{
public:
    Hash_chain chain;
    // Add a data.log entry to the data.logs
    void addLog(string user, string action, string position, bool s)
    {
        string success;
        s ? success = "Done Successfully" : success = "Unsuccessful";
        ofstream fout;
        fout.open("Logs.txt", ios::app);
        fout << "Timestamp: " << getTimestamp()
             << "User: " << user << " " << position << " \t"
             << "Action: " << action << " " << success << "\n\n";
        fout.close();
        chain.AddBlock(getTimestamp(), action, user, position, s);
        chain.writeChain();
    }
};
#endif