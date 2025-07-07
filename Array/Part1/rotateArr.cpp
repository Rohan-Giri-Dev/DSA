//Rotate array by 1 place
#include <iostream>
#include <vector>
using namespace std;

void rotateArr(vector<int> &arr)
{
    int n = arr.size();
    int temp = arr[0];
    for(int i=1; i<n; i++)
    {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}

void printArr(vector<int> &arr)
{
    for(auto i = arr.begin() ; i != arr.end(); i++)
    {
        cout<<*i<<" ";
    }
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    printArr(arr);
    cout<<endl;
    rotateArr(arr);
    printArr(arr);
}