#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

// this problem is to find the longest sub array with sum 0
int maxLen(vector<int> &arr)
{
    int n = arr.size();

    // this is to store the sum and its index
    unordered_map<long long, int> mpp;

    int maxLen = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxLen = max(maxLen, i + 1);
        }
        else
        {
            if (mpp.find(sum) != mpp.end())
            {
                maxLen = max(maxLen, i - mpp[sum] );
            }
            else
            {
                mpp[sum] = i;
            }
        }
    }

    return maxLen;
}

int main()
{
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    // vector<int> arr = {2, 10, 4};
    int ans = maxLen(arr);

    cout << "Max Len: " << ans;
}