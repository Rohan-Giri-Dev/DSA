#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> nums)
{
    int n = nums.size();

    sort(nums.begin(), nums.end());
    vector<int> ans;

    long long actualSum = (long long)((n * (n + 1)) / 2);

    long long arrSum = 0;

    int missingNum = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int xorVal = nums[i] ^ nums[i + 1];

        if (xorVal == 0)
        {
            missingNum = nums[i];

            nums[i] = 0;
        }
    }

    for (auto it : nums)
    {
        arrSum += it;
    }

    missingNum = actualSum- arrSum;

    ans.push_back(missingNum);
}