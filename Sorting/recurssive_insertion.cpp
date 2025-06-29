#include <iostream>
using namespace std;

void insertionSort(int arr[], int i, int n)
{
    if( i >= n ) return;

    int j = i;

    while(j > 0 && j && arr[j] < arr[j-1])
    {
        int temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
        j--;
    }

    insertionSort(arr, i+1, n);
}

void print_array(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

int main()
{
    int arr[] = {4,1,6,9,3,5,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    print_array(arr,n);
    insertionSort(arr,1,n);
    print_array(arr,n);


}