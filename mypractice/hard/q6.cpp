#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    long subarrayXor(vector<int> &arr, int k)
    {
        // code here
        long long count = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            int curXor = 0;
            for (int j = i; j < n; j++)
            {
                curXor = curXor ^ arr[j];

                if (curXor == k)
                {
                    count++;
                }
            }
        }

        return count;
    }
};

int main(){
    // vector<int> arr = {4, 2, 2, 6, 4};
    vector<int> arr = {1 ,3, 7, 9, 5, 9, 9};

    Solution s;
    int ans = s.subarrayXor(arr, 2);

    cout<<"Longest subarray: "<< ans;
}