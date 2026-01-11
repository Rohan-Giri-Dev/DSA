#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int ans;

        long long nSum = (n * (n + 1)) / 2;
        long long acutualSum = 0;

        for (int i = 0; i <= n - 1; i++)
        {
            acutualSum += nums[i];
        }

        ans = nSum - acutualSum;

        return ans;
    }
};