#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int maxLength(vector<int> &arr)
{
    // code here

    unordered_map<long long, int> mpp;

    int maxLen = 0;
    int sum = 0;

    for (int i = 0; i < (int)arr.size(); i++)
    {
        sum += arr[i];

        if (sum == 0)
        {
            maxLen = max(maxLen, i + 1);
        }

        if (mpp.find(sum) != mpp.end())
        {
            maxLen = max(maxLen, i - mpp[sum]);
        }
        else
        {
            mpp[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};

    int ans = maxLength(arr);
    cout << "Max Length: " << ans;
}