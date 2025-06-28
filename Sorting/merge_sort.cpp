#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    int left = low;
    int right = mid+1;
    vector<int> temp;

    while( left <= mid && right <= high)
    {
        if(arr[left] <= arr[right] )
    {
        temp.push_back(arr[left]);
        left++;
    }
    else if(arr[left]>arr[right]){
        temp.push_back(arr[right]);
        right++;
    }

    }

    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = 0; i<temp.size(); i++)
    {
        arr[low+i] = temp[i];
    }

}

void mergeSort(vector<int> &arr , int low, int high)
{
    if(low >= high) return;

    int mid = (low+high)/2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr,low, mid, high);
}

void printArray(vector<int> &arr)
{
    for(auto i = arr.begin(); i != arr.end(); ++i)
    {
        cout<<*i<<" ";
    }
}

int main()
{
    vector<int> arr = {6, 1, 3, 2, 5};
    printArray(arr);
    cout<<endl;
    mergeSort(arr,0,arr.size()-1);
    printArray(arr);

}