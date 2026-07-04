#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // swap everything
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (auto &row : matrix)
    {
        reverse(row.begin(), row.end());
    }
}


/*
working explanation of this code

first we have this array
1 2 3           1 4 7               7 4 1
4 5 6  -> swap  2 5 8   -> reverse  8 5 2
7 8 9           3 6 9               9 6 3

first we swap arr[i][j] -> arr[j][i] 
and then we just reverse it 

this is the simple logic


*/