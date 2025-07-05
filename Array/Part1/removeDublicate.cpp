// Removing duplicates from an araray
#include <iostream>
#include <vector>
using namespace std;

bool checkSorted(vector<int> &arr)
{
   for(int i=1; i<arr.size(); i++)
   {
    if(arr[i] >= arr[i-1])
    {
        
    }
    else {
        return false;
    }
   }

   return true;

}

void printArray(vector<int> &arr)
{
    for(auto i = arr.begin() ; i != arr.end(); i++)
    {
        cout<<*i<<" "<<endl;
    }
}

void removeDublicate(vector<int> &arr)
{
    vector<int> temp;
    int check = checkSorted(arr);
    if(check == 1)
    {
        temp.push_back(arr[0]);
        for(int i=1; i<arr.size(); i++)
        {
                if(arr[i] != arr[i-1] )
                {
                    temp.push_back(arr[i]);
                    
                }
        }
    }

    cout<<"Temp array size: "<<temp.size()<<endl;
    arr = temp;
}


int main()
{
    vector<int> arr = {1,1,2,2,3,3,4,4};
    // cout<<checkSorted(arr);
    removeDublicate(arr);
    printArray(arr);
}