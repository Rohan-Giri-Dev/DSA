#include <iostream>
#include <vector>
using namespace std;

vector<int> getFloorAndCeil(vector<int> arr, int x)
{
    int n = arr.size();

    int low = 0;
    int high = n - 1;

    int floor = -1;

    // to find the floor value
    // floor <= x
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] <= x)
        {
            floor = arr[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

     low = 0;
     high = n - 1;

    int celi = arr[n];

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] >= x)
        {
            celi = arr[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return {floor, celi};
}

int main()
{

    vector<int> nums = {3, 4, 4, 7, 8, 10};
    int x = 5;

    vector<int> ans = getFloorAndCeil(nums, x);

    cout << "Floor: " << ans[0] << endl;
    cout << "Ceil: " << ans[1] << endl;

    return 0;
}