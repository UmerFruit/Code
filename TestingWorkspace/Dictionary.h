#ifndef DICTIONARY_H_
#define DICTIONARY_H_
#include "Headers.h"
using namespace std;
template <typename T1, typename T2>
class Dictionary
{
private:
    using pair_type = Pair<T1, T2>;
    vector<pair_type> entries;

public:
    Dictionary() { }
    void add(T1 key, T2 value)
    {
        entries.push_back(pair_type(key, value));
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
    Dictionary(vector<pair_type> store)
    {
        for(int i = 0;i<store.size();i++)
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
        unsigned int pos = find(entries.begin(), entries.end(), key) - entries.begin();
        return values[pos];
    }
};
#endif // DICTIONARY_H_INCLUDED