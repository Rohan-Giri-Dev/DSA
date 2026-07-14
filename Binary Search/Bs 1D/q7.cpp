// 33. Search in Rotated Sorted Array

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &arr, int target)
    {
        int n = arr.size();

        int l = 0;     // left boundary of search space
        int r = n - 1; // right boundary of search space

        while (l <= r)
        {
            int mid = (l + r) / 2;

            // Found the target
            if (arr[mid] == target)
                return mid;

            // Check which half is sorted: left half [l..mid] or right half [mid..r]
            if (arr[l] <= arr[mid])
            {
                // Left half is sorted (arr[l] <= arr[mid])

                if (target >= arr[l] && target < arr[mid])
                {
                    // target lies within the sorted left half -> search left
                    r = mid - 1;
                }
                else
                {
                    // target must be in the right half -> search right
                    l = mid + 1;
                }
            }
            else
            {
                // Right half is sorted (since left half isn't)

                if (target > arr[mid] && target <= arr[r])
                {
                    // target lies within the sorted right half -> search right
                    l = mid + 1;
                }
                else
                {
                    // target must be in the left half -> search left
                    r = mid - 1;
                }
            }
        }

        // Target not found in the array
        return -1;
    }
};