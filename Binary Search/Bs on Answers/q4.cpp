// 1283. Find the Smallest Divisor Given a Threshold
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Given a candidate divisor 'mid', compute the sum of ceiling(x / mid) for all elements.
    // This tells us the total if we divide every element by 'mid' and round up.
    int isSmall(vector<int> &nums, int mid, int threshold)
    {
        int n = nums.size();
        int divSum = 0;
        for (auto &x : nums)
        {
            // Ceiling division without floats: (x + mid - 1) / mid
            // Adding (mid - 1) pushes any nonzero remainder into the next bucket,
            // but doesn't affect exact multiples.
            divSum += (x + mid - 1) / mid;
        }

        return divSum;
    }

    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int n = nums.size();

        // Search space for the divisor:
        // Smallest possible divisor is 1.
        // Largest useful divisor is max(nums), since any divisor >= max element
        // makes every division result exactly 1 (the smallest each term can be).
        int l = 1;
        int r = *max_element(begin(nums), end(nums));

        // Binary search for the smallest divisor that keeps the sum <= threshold.
        // This works because as 'mid' (the divisor) increases, the sum is
        // monotonically non-increasing -- classic "binary search on the answer."
        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (isSmall(nums, mid, threshold) <= threshold)
            {
                // This divisor works (sum is small enough).
                // It might not be the smallest one that works, though,
                // so keep it as a candidate and search the left half.
                r = mid;
            }
            else
            {
                // This divisor's sum is too big -- it doesn't satisfy the condition.
                // Any divisor <= mid would only make the sum bigger (or equal),
                // so we can safely discard mid and everything below it.
                l = mid + 1;
            }
        }

        // l == r here, and it's the smallest divisor satisfying sum <= threshold.
        return l;
    }
};