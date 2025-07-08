//Moving all the zero to the right side of the array
#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> &arr)
{
    for(auto i = arr.begin() ; i != arr.end(); i++)
    {
        cout<<*i<<" ";
    }
}
void moveArr(vector<int> &arr)
{
    vector<int> temp;
    int n = arr.size();
    int count = 0;

    for(int i=0; i<n; i++)
    {
        if(arr[i] >= 1)
        {
            temp.push_back(arr[i]);
        }
        else{
            count ++;
        }

    }
    int sizeTemp = temp.size();

    for(int i = sizeTemp; i<sizeTemp+count; i++)
    {
        temp.push_back(0);
    }

    arr = temp;
}



int main()
{
    vector<int> arr = {1,0,2,0,0,3,4,5,0,6};
    printArr(arr);
    cout<<endl;
    moveArr(arr);
    printArr(arr);

}