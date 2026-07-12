#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int> &arr, int n, int k)
{
    int low = 0;
    int high = n - 1;

    int first = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == k)
        {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return first;
}

int lastOccurence(vector<int> &arr, int n, int k)
{
    int low = 0;
    int high = n - 1;

    int last = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == k)
        {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return last;
}

vector<int> firstAndLastOccurence(vector<int> &arr, int n, int k)
{
    int first = firstOccurence(arr, n, k);
    int last = lastOccurence(arr, n, k);

    vector<int> ans({first, last-1});

    return ans;
}