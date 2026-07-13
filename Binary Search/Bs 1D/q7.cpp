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

        int l = 0;     // left
        int r = n - 1; // right

        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (arr[mid] == target)
                return mid;

            if (arr[l] <= arr[mid])
            {
                if (target >= arr[l] && target < arr[mid])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                if (target > arr[mid] && target <= arr[r])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};