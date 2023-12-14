#ifndef DICTIONARY_H_
#define DICTIONARY_H_
#include <vector>
using namespace std;
template <class T1, class T2>
class Pair
{
public:
    T1 first;
    T2 second;
    Pair(T1 first, T2 second)
    {
        this->first = first;
        this->second = second;
    }
    Pair() {}
};
template <class T1, class T2>
class Dictionary
{
public:
    vector<Pair<T1, T2> > entries;

public:
    Dictionary() { entries.clear(); }
    void add(T1 key, T2 value)
    {
        entries.push_back(Pair<T1, T2>(key, value));
    }
    bool find(T1 targetKey) const
    {
        for (int i = 0; i < entries.size(); i++)
        {
            if (entries[i].first == targetKey)
            {
                return true;
            }
        }
        return false;
    }
    T1 &getkey(int i)
    {
        return entries[i].first;
    }
    int getidx(T1 targetKey) const
    {
        for (int i = 0; i < entries.size(); i++)
        {
            if (entries[i].first == targetKey)
            {
                return i;
            }
        }
        return -1;
    }
    void remove(T1 targetKey)
    {
        int pos = getidx(targetKey);
        if (pos == -1)
        {
            cout << "Key not found" << endl;
            return;
        }
        entries.erase(entries.begin() + pos);
    }
    void replace(T1 targetKey, T2 newValue)
    {
        int pos = getidx(targetKey);
        if (pos == -1)
        {
            cout << "Key not found" << endl;
            return;
        }
        entries[pos].second = newValue;
    }
    void clear()
    {
        entries.clear();
    }
    int size() const
    {
        return entries.size();
    }
    bool isEmpty() const
    {
        return entries.size() == 0;
    }
    T2 &getval(int i)
    {
        return entries[i].second;
    }
    T2 &operator[](T1 key)
    {
        int pos;
        if (find(key))
        {
            pos = getidx(key);
        }
        else
        {
            T2 temp;
            add(key, temp);
            pos = getidx(key);
        }
        return entries[pos].second;
    }
};
#endif // DICTIONARY_H_INCLUDED