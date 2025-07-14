// Sort colors 
/* Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]*/

#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int n = nums.size();
    vector<int> temp;
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    for(int i=0; i<n; i++)
    {
        if(nums[i] == 0) cnt0++;
        else if(nums[i] == 1) cnt1++;
        else cnt2++;
    }
    // for putting 0 in the array
    for(int i=0; i<cnt0; i++)
    {
        temp.push_back(0);
    }
    // for putting 1's in the array
    for(int i=cnt1; i<cnt1+cnt0; i++)
    {
        temp.push_back(1);
    }
    // for putting 2's in the array
    for(int i=cnt2; i<cnt2+cnt1; i++)
    {
        temp.push_back(2);
    }

    nums = temp;

    for(auto it : nums)
    {
        cout<<it<<" ";
    }
        
}

int main()
{
    vector<int> arr = {2,0,2,1,1,0};
    vector<int> arr1 = {0};
    sortColors(arr);
    cout<<endl;
    sortColors(arr1);
}