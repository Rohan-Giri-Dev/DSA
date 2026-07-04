#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;

        int count = 0;

        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (arr[left] < arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            // when the right is smaller
            else if (arr[right] == arr[left])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                count += (mid - left + 1);
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }

        return count;
    }

    int mergeSort(vector<int> &arr, int low, int high)
    {
        int count = 0;
        if (low == high)
            return count;

        int mid = (low + high) / 2;

        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);

        return count;
    }

    int inversionCount(vector<int> &nums)
    {

        // Code Here
        int low = 0;
        int high = nums.size() - 1;

        return mergeSort(nums, low, high);
    }
};

int main()
{
    Solution s;

    // vector<int> arr = {2, 4, 1, 3, 5};
    vector<int> arr = {10, 10, 10};

    int ans = s.inversionCount(arr);

    cout << "Number of inversions: " << ans;
}
