// Majority Element is the element that appears more than ⌊n / 2⌋ times.

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int majorityElement(vector<int>& arr) {
    int n = arr.size();
    int res=-1;
    map<int,int> mpp;

    for(int i=0; i<n; i++)
    {
        mpp[arr[i]]++;
    }

    for(auto it : mpp)
    {
        if(it.second > n/2)
        {
            res=it.first;
            // cout<<it.first;
        }
    }
    return res;

}

int main()
{
    vector<int> arr =  {2,2,1,1,1,2,2};
    vector<int> arr1 =  {3,2,3};
    cout<<majorityElement(arr);
    cout<<endl;
    cout<<majorityElement(arr1);

}