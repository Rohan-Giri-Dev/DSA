#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> longestConsecutive(vector<int>& nums) {

    vector<int> res;
    sort(nums.begin(), nums.end()); 
    int sum=0;

    for(int i=1; i<nums.size(); i++)
    {
        sum = nums[i] - nums[i-1];
        if(sum == -1){
            res.push_back(nums[i]);
        }
    }

    return res;
        
}

int main()
{
    vector<int> arr = {100, 200, 1, 3, 2, 4};
    vector<int> ans = longestConsecutive(arr);

    for(auto i : ans){
        cout<<i<<" ";
    }
}