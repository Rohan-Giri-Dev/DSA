// 3731. Find Missing Elements
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> findMissingElements(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> temp;

        int smallest = nums[0];
        int largest = nums[n - 1];
        int j = 0;

        for (int i = smallest; i <= largest; i++)
        {
            if (j < n && nums[j] == i)
            {
                while (j < n && nums[j] == i)
                    j++; // consume all duplicates of i
            }
            else
            {
                temp.push_back(i); // i missing entirely
            }
        }

        return temp;
    }
};