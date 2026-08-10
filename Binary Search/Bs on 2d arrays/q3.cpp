// 1901. Find a Peak Element II
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxRowIndex(vector<vector<int>> &mat, int n, int m, int col)
    {
        int maxVal = 0;
        int index = -1;

        for (int i = 0; i < n; i++)
        {
            if (mat[i][col] > maxVal)
            {
                maxVal = mat[i][col];
                index = i;
            }
        }

        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        int l = 0, r = m - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int row = maxRowIndex(mat, n, m, mid); // this will give the row index of the maximum element in the mid column

            // all outer bound is considered -1
            int left = (mid - 1 >= 0) ? mat[row][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[row][mid + 1] : -1;

            if (mat[row][mid] > left && mat[row][mid] > right)
            {
                return {row, mid};
            }
            else if (mat[row][mid] < left)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return {-1, -1};
    }
};