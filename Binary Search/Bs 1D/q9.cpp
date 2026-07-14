// leet code 153
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0;     // left boundary of search window
        int r = n - 1; // right boundary of search window

        // Keep shrinking the window until l and r meet.
        // When l == r, that single position holds the minimum.
        while (l < r)
        {
            int mid = (l + r) / 2;

            // If nums[mid] > nums[r], the array must "break" (rotate)
            // somewhere in the right half (mid, r]. That means:
            // - nums[mid] itself CANNOT be the minimum (something smaller exists to its right)
            // - so we discard the left portion including mid, and search (mid+1, r]
            if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            // Otherwise, nums[mid] <= nums[r], meaning the segment [mid, r]
            // is sorted normally (no rotation break inside it).
            // - The minimum must be at mid or somewhere to its left
            // - So we keep mid as a candidate and search [l, mid]
            else
            {
                r = mid;
            }
        }

        // l == r here, pointing to the smallest element
        return nums[r];
    }
};