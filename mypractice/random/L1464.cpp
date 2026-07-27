// 1464. Maximum Product of Two Elements in an Array
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();

        int maxNum1 = 0;
        int maxNum2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > maxNum1)
            {
                maxNum2 = maxNum1;
                maxNum1 = nums[i];
            }
            else if (nums[i] > maxNum2)
            {
                maxNum2 = nums[i];
            }
        }

        int ans = (maxNum1 - 1) * (maxNum2 - 1);

        return ans;
    }
};