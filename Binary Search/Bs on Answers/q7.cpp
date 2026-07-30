// 410. Split Array Largest Sum
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool canSplit(vector<int> &nums, int mid, int k)
    {
        int cnt = 1; // at least one subarray to hold the first element
        int sum = 0;

        for (int &x : nums)
        {
            if (sum + x > mid)
            {
                cnt++;   // start a new subarray
                sum = x; // current element goes into the new subarray
            }
            else
            {
                sum += x; // element fits in current subarray
            }
        }

        return cnt <= k;
    }
    int splitArray(vector<int> &nums, int k)
    {
        int left = *max_element(nums.begin(), nums.end()); // can't go below largest element
        int right = 0;
        for (auto &x : nums)
            right += x;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (canSplit(nums, mid, k))
            {
                right = mid; // mid works, try smaller
            }
            else
            {
                left = mid + 1; // mid too small, need bigger
            }
        }

        return left;
    }
};

int main()
{
    Solution sol;

    // Test 1
    vector<int> nums1 = {7, 2, 5, 10, 8};
    int m1 = 2;
    cout << "Test 1: " << sol.splitArray(nums1, m1)
         << " (expected 18)" << endl;

    // Test 2
    vector<int> nums2 = {1, 2, 3, 4, 5};
    int m2 = 2;
    cout << "Test 2: " << sol.splitArray(nums2, m2)
         << " (expected 9)" << endl;

    // Test 3
    vector<int> nums3 = {1, 4, 4};
    int m3 = 3;
    cout << "Test 3: " << sol.splitArray(nums3, m3)
         << " (expected 4)" << endl;

    // Edge case: only one subarray allowed -> sum of whole array
    vector<int> nums4 = {5, 5, 5, 5};
    int m4 = 1;
    cout << "Test 4: " << sol.splitArray(nums4, m4)
         << " (expected 20)" << endl;

    // Edge case: m equals array size -> largest single element
    vector<int> nums5 = {2, 3, 1, 1, 4};
    int m5 = 5;
    cout << "Test 5: " << sol.splitArray(nums5, m5)
         << " (expected 4)" << endl;

    return 0;
}