#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> longestConsecutive(vector<int>& nums) {

    vector<int> res;
    sort(nums.begin(), nums.end()); 
    // int sum=0;

    for(int i=0; i<nums.size(); i++)
    {
        int curr = nums[i];
        vector<int> temp =  {curr};

        while(find(nums.begin(),nums.end(), curr + 1) != nums.end())
        {
            temp.push_back(nums[curr]);
            curr++;
        }

        if(temp.size() > res.size()) res = temp;
    }


    return res;
        
}

int main()
{
    vector<int> arr = {100, 200, 1, 3, 2, 4};
    vector<int> arr1 = {3, 8, 5, 7, 6};
    vector<int> ans = longestConsecutive(arr);
    vector<int> ans1 = longestConsecutive(arr);

    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i : ans1){
        cout<<i<<" ";
    }
}