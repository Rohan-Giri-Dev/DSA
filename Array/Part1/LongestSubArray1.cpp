// Longest Subarray with given Sum K(Positives)
#include <iostream>
#include <vector>
using namespace std;

int longestSubarray(vector<int> &arr, int k)
{
    int n = arr.size();
    int left = 0, right = 0;
    long long sum = arr[0];
    int maxLen = 0;

    while( right < n)
    {
        if(left <= right && sum > k)
        {
            sum -= arr[left];
            left++;

        }

        if(sum == k)
        {
            maxLen = max(maxLen, right-left+1);
        }

        right++;
        if(right < n) sum += arr[right];
    }
    return maxLen;

}

int main()
{
    vector<int> arr = {1,2,3,1,1,1,1,4,2,3};
    cout<<longestSubarray(arr,3);

}