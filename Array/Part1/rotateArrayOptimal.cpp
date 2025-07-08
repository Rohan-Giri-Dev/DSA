#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void arrRotate(vector<int> &arr, int d)
{
    int n = arr.size();
    d = d % n; // handle d > n

    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}

void printArray(const vector<int> &arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    cout << "Original array: ";
    printArray(arr);

    int d = 3;
    arrRotate(arr, d);

    cout << "Rotated array by " << d << " places: ";
    printArray(arr);

    return 0;
}
