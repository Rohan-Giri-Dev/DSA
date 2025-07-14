#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<int> temp;

    for(int i=0; i<n ;i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i == j) continue;
            if(arr[i]+arr[j] == target)
            {
                temp.push_back(i);
            }
        }
    }

    return temp;
}

int main()
{
    vector<int> arr = {2,7,11,15};
    vector<int> arr1 = {3,2,4};
    vector<int> res = twoSum(arr,9); 
    vector<int> res1 = twoSum(arr1,6);

    for(auto it : res)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it : res1)
    {
        cout<<it<<" ";
    }
}