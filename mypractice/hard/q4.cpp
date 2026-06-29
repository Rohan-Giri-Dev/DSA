#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> fourSum(vector<int> nums, int target)
{
    vector<vector<int>> ans;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = n - 1; j >= 0; j--)
        {
            if (j < n - 1 && nums[j] == nums[j + 1])
                continue;

            int l = i + 1;
            int r = j - 1;

            while (l < r)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];

                if (sum < target)
                {
                    l++;
                }
                else if (sum > target)
                {
                    r--;
                }
                else
                {
                    ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                    l++;
                    r--;

                    while (l < r && nums[l] == nums[l - 1] && l - 1 != i)
                        l++;
                    while (l < r && nums[r] == nums[r + 1] && r + 1 != j)
                        r--;
                }
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 0, -1, 0, -2, 2};

    vector<vector<int>> ans = fourSum(arr, 0);

    for (auto it : ans)
    {
        cout << "[ ";
        for (auto x : it)
        {
            cout << x << " ";
        }
        cout << "],";
        cout << endl;
    }
}