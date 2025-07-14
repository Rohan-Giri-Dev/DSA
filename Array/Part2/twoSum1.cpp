#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& arr, int target) {
    map<int,int> mpp;
    int n = arr.size();
    for(int i=0; i<n; i++)
    {
        int a = arr[i];
        int more = target - a;

        if(mpp.find(more) != mpp.end())
        {
            return {mpp[more], i};
        }

        mpp[a] = i;
    }

    return {-1,-1};
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