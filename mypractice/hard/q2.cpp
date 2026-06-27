// leet code 229. Majority Element II

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = (nums.size()) / 3;
        vector<int> ans;

        map<int, int> mpp;

        for (auto x : nums)
        {
            mpp[x]++;
        }

        for (auto it : mpp)
        {
            if (it.second > n)
            {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};

int main()
{
    Solution s1;
    vector<int> q = {3, 2, 3};

    vector<int> ans = s1.majorityElement(q);

    for (auto x : ans)
    {
        cout << x << "";
    }
}