#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> &arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

void moveArr(vector<int> &arr)
{
    int n = arr.size();
    int j = 0; // index for placing non-zero elements

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main()
{
    vector<int> arr = {1, 0, 2, 0, 0, 3, 4, 5, 0, 6};
    cout << "Before: ";
    printArr(arr);

    moveArr(arr);

    cout << "After: ";
    printArr(arr);

    return 0;
}
