// #include "Headers.h"
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

template <typename T, typename U>
class Dictionary
{
private:
    vector<T> keys;
    vector<U> values;

public:
    Dictionary()
    {
    }
    bool has(T) const;
    void add(T, U);
    T *begin();
    T *end();
    U operator[](T);
};

template <typename T, typename U>
T *Dictionary<T, U>::begin()
{
    return &(keys[0]);
}

template <typename T, typename U>
T *Dictionary<T, U>::end()
{
    return &(keys[keys.size() - 1]) + 1;
}
template <typename T, typename U>
bool Dictionary<T, U>::has(T targetKey) const
{
    for (T currentKey : keys)
    {
        if (currentKey == targetKey)
        {
            return true;
        }
    }
    return false;
}

template <typename T, typename U>
void Dictionary<T, U>::add(T key, U value)
{
    keys.push_back(key);
    values.push_back(value);
}

template <typename T, typename U>
U Dictionary<T, U>::operator[](T key)
{
    unsigned int pos = find(keys.begin(), keys.end(), key) - keys.begin();
    return values[pos];
}

int main()
{
    Dictionary<int, string> d;
    string s = "umer";
    d.add(1, s);
    d.add(2, "saif");
    cout << d[1] << endl;

    cout << d[2] << endl;

    // d.add(2, "saif");
    // d.add(3, "maleek");
    // d.add(4, "bilal");
}