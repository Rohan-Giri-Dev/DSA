// 4. Median of Two Sorted Arrays
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        double ans = 0;

        vector<int> temp;

        int i = 0;
        int j = 0;

        while (i < n && j < m)
        {
            if (nums1[i] <= nums2[j])
            {
                temp.push_back(nums1[i]);
                i++;
            }
            else
            {
                temp.push_back(nums2[j]);
                j++;
            }
        }

        while(i < n)
        {
            temp.push_back(nums1[i]);
            i++;
        }
        while(j < m)
        {
            temp.push_back(nums2[j]);
            j++;
        }

        int tempSize = temp.size();

        if(tempSize % 2 == 0){ //even;
            int mid = tempSize/2;
            ans = (double)(temp[mid]+temp[mid-1])/(double)2;
        }else{
            int mid = tempSize / 2;
            ans = temp[mid];
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> a1 = {1, 3}, b1 = {2};
    cout << fixed << setprecision(5);
    cout << "Expected: 2.00000, Got: " << sol.findMedianSortedArrays(a1, b1) << "\n";

    vector<int> a2 = {1, 2}, b2 = {3, 4};
    cout << "Expected: 2.50000, Got: " << sol.findMedianSortedArrays(a2, b2) << "\n";

    return 0;
}