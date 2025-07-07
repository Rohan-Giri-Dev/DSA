#include <iostream>
#include <vector>
// #include <UtilLib.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low -1;

    for(int j = low; j<high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[high]);
    return i+1;

}

void quickSort(vector<int> &arr, int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr,low,high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void printArray(vector<int> &arr)
{
    for(auto i = arr.begin(); i != arr.end(); ++i)
    {
        cout<<*i<<" ";
    }
}

int main(){

    vector<int> arr = {7, 2, 1, 6, 8, 5, 3, 4};
    printArray(arr);
    cout<<endl;
    quickSort(arr,0,arr.size());
    printArray(arr);

}
