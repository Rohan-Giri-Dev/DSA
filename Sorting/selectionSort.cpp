#include <iostream>
using namespace std;

void selection_sort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min=i;
        for(int j= i+1; j<n-1 ; j++)
        {
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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
    int arr[] = {4,1,6,9,3,5,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    print_array(arr,n);
    selection_sort(arr,n);
    print_array(arr,n);


}