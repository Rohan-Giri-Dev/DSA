#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr1, int m, vector<int> &arr2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0)
    {
        if (arr1[i] > arr2[j])
        {
            arr1[k] = arr1[i];
            k--;
            i--;
        }
        else
        {
            arr1[k] = arr2[j];
            k--;
            j--;
        }
    }

    while (j >= 0)
    {
        arr1[k] = arr2[j];
        j--;
        k--;
    }
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 0, 0, 0};
    vector<int> arr2 = {2, 5, 6};

    merge(arr1, 3, arr2, 3);

    for (auto it : arr1)
    {
        cout << it << " ";
    }
}

/*

we have two arrays arr1 && arr2

we can run loop from the last index of arr1 as itt has more free spaces (0)
arr1 = 1 2 3 0 0 0
arr2 = 2 5 6

i = m-1 = 3-1= 2
j = n-1 = 3-1 = 2

arr1=[1,2,3,0,0,0], m=3, arr2=[2,5,6], n=3

i=2,j=2,k=5: 3 > 6? No → arr1[5]=6, j=1,k=4

i=2,j=1,k=4: 3 > 5? No → arr1[4]=5, j=0,k=3

i=2,j=0,k=3: 3 > 2? Yes → arr1[3]=3, i=1,k=2

i=1,j=0,k=2: 2 > 2? No → arr1[2]=2, j=-1,k=1

j=-1 → main loop exits (j>=0 false)
Cleanup loop: j>=0 false → doesn't run

*/