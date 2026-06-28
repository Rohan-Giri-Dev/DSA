// leet code 15 3Sum
/*Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter. */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> arr)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        int r = arr.size() - 1;
        int l = i + 1;

        while (l < r)
        {
            int sum = arr[i] + arr[r] + arr[l];

            if (sum < 0)
            {
                l++;
            }
            else if (sum > 0)
            {
                r--;
            }
            else
            {
                ans.push_back({arr[i], arr[l], arr[r]});
                r--;
                l++;

                // this is to check if the current value is similar to the previous value or not .
                // To avoid dublicates and rechecking

                while (l < r && arr[r] == arr[r + 1])
                    r--;
                while (l < r && arr[l] == arr[l - 1])
                    l++;
            }
        }
    }

    return ans;
}