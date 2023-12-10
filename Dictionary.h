#ifndef DICTIONARY_H_
#define DICTIONARY_H_
#include <algorithm>
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
private:
    vector<Pair<T1, T2>> entries;

public:
    Dictionary() {}
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

    Dictionary(vector<Pair<T1, T2>> store)
    {
        for (int i = 0; i < store.size(); i++)
        {
            add(store[i].first, store[i].second);
        }
    }
    T1 *begin()
    {
        return &(entries[0].first);
    }
    T1 *end()
    {
        return &(entries[entries.size() - 1]);
    }
    T2 operator[](T1 key)
    {
        int pos = getidx(key);
        if (pos == -1)
            // cout << "Key not found" << endl;
            throw std::runtime_error("Key not found");
        else
            return entries[pos].second;
    }
};
#endif // DICTIONARY_H_INCLUDED