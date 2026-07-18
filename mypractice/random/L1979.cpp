// 1979. Find Greatest Common Divisor of Array
/*Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.



Example 1:

Input: nums = [2,5,6,9,10]
Output: 2
Explanation:
The smallest number in nums is 2.
The largest number in nums is 10.
The greatest common divisor of 2 and 10 is 2.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findGCD(vector<int> &nums){
    int n = nums.size();

    sort(nums.begin(), nums.end());  // sort to find the smallest nums and largest num

    int small = nums[0];
    int large = nums[n-1];

    for(int i = small; i>=1; i++){
        if((small % i == 0) && (large % i == 0)){
            return i;
        }
    }

    return -1;
}