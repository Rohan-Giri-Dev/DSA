// 74. Search a 2D Matrix
#include <iostream>
#include <vector>
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

/*
Here's the explanation for **LeetCode 74: Search a 2D Matrix**.

## Problem setup

You're given an `n x m` matrix with two properties:
- Each row is sorted left to right.
- The first number of each row is greater than the last number of the previous row.

Together, these two properties mean that if you read the matrix row by row, left to right, top to bottom, you get one single sorted sequence. That's the key insight — you don't need a 2D search at all. You can binary search as if the matrix were a flattened 1D sorted array.

## Why flatten instead of searching row by row

A naive approach would be to first find the right row, then binary search within that row — two binary searches. But since the whole matrix is really just one sorted list in disguise, you can do it in a single binary search over the range `[0, n*m - 1]`, treating each index `mid` as a position in that imaginary flattened array.

## Mapping a flat index back to (row, col)

Say the matrix has `m` columns. If you had truly flattened it into a 1D array, index `mid` would be sitting inside some row. Since each row holds exactly `m` elements:

- **Which row am I in?** → `row = mid / m` (integer division tells you how many full rows of size `m` fit before this index).
- **Which column within that row?** → `col = mid % m` (the remainder tells you how far into the current row you are).

This is the same logic as converting a 1D array index into 2D grid coordinates in general — divide by the row length to get the row, mod by the row length to get the column.

## The binary search itself

Once you can translate any `mid` into `matrix[row][col]`, the rest is just standard binary search:

```cpp
int start = 0, end = n * m - 1;

while (start <= end) {
    int mid = (start + end) / 2;
    int row = mid / m;
    int col = mid % m;

    if (matrix[row][col] > target) {
        end = mid - 1;      // target is smaller, search left half
    } else if (matrix[row][col] < target) {
        start = mid + 1;    // target is bigger, search right half
    } else {
        return true;        // found it
    }
}
return false;
```

## Complexity

- **Time:** O(log(n·m)) — one binary search over the full flattened range, instead of O(n + log m) or O(log n + log m) for a two-step search.
- **Space:** O(1) — no extra data structures, just index math.

## The bug you had, in one line

You wrote `row = mid / n` and `col = mid % n`, dividing by the row *count* (`n`) instead of the row *length* (`m`). Since rows have `m` elements each, the flattening math has to be based on `m`, not `n`. That's the only thing that needed to change.
*/