// Bubble sort
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for(int i=1; i<n ; i++)
    {
        int j = i-1;
        while(j >= 0 && arr[j] > arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;

            j--;
        }
    }
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
    int arr[] = { 9,4,7,2,5,1,3,8,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    print_array(arr, n);
    insertionSort(arr,n);
    print_array(arr, n);

}
