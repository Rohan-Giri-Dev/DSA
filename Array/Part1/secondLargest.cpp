// Finding the second largest elment in the array

#include <iostream>
#include <vector>
using namespace std;

void sLargest(vector<int> arr)
{
    int largest = arr[0];
    int sLargest = INT_MIN;
    for(int i =1; i<arr.size(); i++)
    {
        if(arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] > sLargest && arr[i] != largest )
        {
            sLargest = arr[i];
        }
    }

    cout<<"Largest element is: "<<largest<<endl;
    cout<<"Second Largest element is: "<<sLargest;

}

int main()
{
    vector<int> arr = {8,1,7,7,5,2,3};
    sLargest(arr);
    
}