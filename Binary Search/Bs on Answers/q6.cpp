/*
Aggressive Cows
Subscribe to TUF+

Hints
Company
Given an array nums of size n, which denotes the positions of stalls, and an integer k, which denotes the number of aggressive cows, assign stalls to k cows such that the minimum distance between any two cows is the maximum possible. Find the maximum possible minimum distance.


Example 1

Input: n = 6, k = 4, nums = [0, 3, 4, 7, 10, 9]

Output: 3

Explanation:

The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions [0, 3, 7, 10]. Here the distances between cows are 3, 4, and 3 respectively.

In no manner can we increase the minimum distance beyond 3.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool canWePlace(vector<int> &nums, int mid, int k)
    {
        int cntCows = 1, last = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] - last >= mid)
            {
                cntCows++;
                last = nums[i];
            }

            if (cntCows == k)
                return true;
        }

        return false;
    }
    int aggressiveCows(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int low = 1, high = nums[n - 1] - nums[0];

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (canWePlace(nums, mid, k) == true)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return high;
    }
};