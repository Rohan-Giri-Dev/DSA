#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        vector<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;
        for (int i = 1; i <= n - 1; i++)
        {
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }

        for (int i = 1; i <= n - 1; i++)
        {
            if ((arr[i] - arr[i - 1]) == minDiff)
            {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> arr = {4, 2, 1, 3};
    Solution sol;
    vector<vector<int>>  ans = sol.minimumAbsDifference(arr);

    for (const auto &row : ans)
    {
        for (const auto &element : row)
        {
            std::cout << element << " ";
        }
        std::cout << std::endl; // Newline after each row
    }
}