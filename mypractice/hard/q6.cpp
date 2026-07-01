#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    long subarrayXor(vector<int> &arr, int k)
    {

        long long xr = 0;

        map<int, int> mpp;

        mpp[xr]++;

        int cnt = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            xr = xr ^ arr[i];

            int x = xr ^ k;

            cnt += mpp[x];
            mpp[xr]++;
        }

        return cnt;
    }
};

int main(){
    // vector<int> arr = {4, 2, 2, 6, 4};
    vector<int> arr = {1 ,3, 7, 9, 5, 9, 9};

    Solution s;
    int ans = s.subarrayXor(arr, 2);

    cout<<"Longest subarray: "<< ans;
}

/*
my solution
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
*/