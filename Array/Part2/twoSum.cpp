#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<int> temp;
    int sum = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            sum = arr[i] + arr[j];
            if(sum == target)
            {
                temp.push_back(arr[i]);
                // temp.push_back(arr[j]);
            }
        }
    }

    return temp;
}

int main()
{
    vector<int> arr = {2,7,11,15};
    vector<int> res = twoSum(arr,9);

    for(auto it : res)
    {
        cout<<it<<" ";
    }
}