#include <iostream>
#include <vector>
using namespace std;

// leet code 1752 
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > nums[(i + 1) % n])
            {
                count++;
                if (count > 1)
                    return false; // early exit
            }
        }
        return true; // count can be 0 or 1
    }
};

int main()
{
    vector<int> arr = {3, 4, 5, 2, 1};
    // 1 2 3 4 5 9 6
    // vector<int> arr1 = {5, 6, 7, 8, 4, 3, 2, 1};
    Solution s1;
    cout << s1.check(arr);
}