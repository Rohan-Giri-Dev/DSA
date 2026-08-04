// 240. Search a 2D Matrix II

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
        int n = matrix.size();    // number of rows
        int m = matrix[0].size(); // number of columns

        // Start from the top-right corner of the matrix.
        // This works because from here, moving left decreases the value
        // and moving down increases the value — giving us a sorted
        // "search direction" in both axes at once.
        int row = 0, col = m - 1;

        while (row < n && col >= 0)
        {
            if (matrix[row][col] == target)
            {
                // Found the target
                return true;
            }
            else if (matrix[row][col] < target)
            {
                // Current value too small — everything in this row to the
                // left is even smaller, so move down to a bigger row (larger values)
                row++;
            }
            else
            {
                // Current value too large — everything below in this column
                // is even larger, so move left to eliminate this column
                col--;
            }
        }

        // Ran off the matrix without finding target
        return false;
    }
};

int main()
{
    // Sample matrix: rows sorted left-to-right, columns sorted top-to-bottom
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};

    Solution sol;

    // Each test case: {target value, expected result}
    vector<pair<int, bool>> tests = {
        {5, true},
        {20, false},
        {30, true},
        {1, true},
        {0, false},
        {26, true}};

    // Run each test and print a pass/fail report
    for (auto &[target, expected] : tests)
    {
        bool result = sol.searchMatrix(matrix, target);
        cout << "target = " << setw(3) << target
             << " | got: " << boolalpha << result
             << " | expected: " << expected
             << " | " << (result == expected ? "PASS" : "FAIL")
             << endl;
    }

    return 0;
}