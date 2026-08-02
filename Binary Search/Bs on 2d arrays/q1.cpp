// 74. Search a 2D Matrix

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int start = 0;
        int end = n * m - 1;

        while (start <= end)
        {
            int mid = (start + end) / 2;

            int row = mid / m; // was mid / n
            int col = mid % m; // was mid % n

            if (matrix[row][col] > target)
            {
                end = mid - 1;
            }
            else if (matrix[row][col] < target)
            {
                start = mid + 1;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};