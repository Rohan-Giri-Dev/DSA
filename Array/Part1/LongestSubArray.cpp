// Longest Subarray with given Sum K(Positives)
#include <iostream>
#include <vector>
using namespace std;

vector<int> longestSubarray(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> temp;

    int sum = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<k; j++)
        {
            sum += arr[j];
            temp.push_back(arr[j]);
            if(sum == k && temp.size() == k)
            {
                return temp;
            }
            else return temp = {0};
        }
    }

    return temp;
}

int main()
{
    vector<int> arr = {1,2,3,1,1,1,1,4,2,3};
    vector<int> res = longestSubarray(arr,3);

    for(auto it: res)
    {
        cout<<it<<" ";
    }

}