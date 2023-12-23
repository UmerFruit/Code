#include <vector> 
#include <iostream>
using namespace std;

class NumArray
{
public:
    vector<int> arr;
    // Initialize here.
    NumArray(vector<int> &arr, int n)
    {
        // Write your code here.
        this->arr = arr;
    }

    // Update operation.
    void update(int l, int r, int val)
    {
        for(int i=0;i<=r-l;i++)
        {
            arr[l+i] += val+i;
        }
    }

    // Return the sum of subarray arr[l..r].
    long long rangeSum(int l, int r)
    {
        long long sum = 0;
        for(int i =l;i<=r;i++)
        {
            sum+= arr[i];
        }
        return sum;
    }
};
int main() {
    vector<int> arr = {0,1,1,1,0};
    NumArray a(arr,4);
    cout<<a.rangeSum(1,4)<<endl;

}