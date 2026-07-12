// leetcode 540. Single Element in a Sorted Array
#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int> &nums){
    int n = nums.size();

    if( n == 1){
        return nums[0];
    }

    int l = 0; // left
    int r = n-1; // right

    while ( l <= r){
        if(l+1 < n && nums[l] == nums[l+1]){
            l += 2;
        }
        else if( r-1 >=0 && nums[r] == nums[r-1]){
            r -= 2;
        }
        else{
            if(nums[l] != nums[l+1]){
                return nums[l];
            }
            else if (nums[r] != nums[r - 1])
            {
                return nums[r];
            }
    }
}

    return -1;
}