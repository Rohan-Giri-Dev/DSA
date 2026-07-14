// 81. Search in Rotated Sorted Array II
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool search(vector<int> &arr, int target)
    {

        int l = 0;
        int r = arr.size() - 1;

        while (l <= r)
        {

            int mid = l + (r - l) / 2;

            if (arr[mid] == target)
                return true;

            // Handle duplicates
            if (arr[l] == arr[mid] && arr[mid] == arr[r])
            {
                l++;
                r--;
            }

            // Left half sorted
            else if (arr[l] <= arr[mid])
            {

                if (target >= arr[l] && target < arr[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }

            // Right half sorted
            else
            {

                if (target > arr[mid] && target <= arr[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }

        return false;
    }
};