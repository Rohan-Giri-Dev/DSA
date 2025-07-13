// Longest Subarray with given Sum K(Positives)
#include <iostream>
#include <vector>
using namespace std;

vector<int> longestSubarray(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> temp;
    int len = 0;

    for(int i=0; i<n; i++)
    {
        int sum = 0;
        for(int j=i; j<n; j++)
        {
            sum += arr[j];
           if (sum == k && (j - i + 1) > len) {
            len = j - i + 1;  // Update length

            temp.clear(); // Clear previous subarray

        for (int p = i; p <= j; p++) {
        temp.push_back(arr[p]);
    }
    }

        }
    }

    return temp;
}

int main()
{
    vector<int> arr = {1,2,3,1,1,1,1,4,2,3};
    vector<int> arr1 = {1,2,3,1,1,1,1,4,2,3};
    vector<int> res = longestSubarray(arr,3);
    vector<int> res1 = longestSubarray(arr,3);

    for(auto it: res)
    {
        cout<<it<<" ";
    }
    for(auto it: res1)
    {
        cout<<it<<" ";
    }

}