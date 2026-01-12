#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;
        int maxi = 0;

        for (int i = 0; i <= n - 1; i++)
        {
            if (nums[i] != 0)
            {
                count++;
                maxi = max(count, maxi);
            }
            else
            {
                count = 0;
            }
        }

        return maxi;
    }
};