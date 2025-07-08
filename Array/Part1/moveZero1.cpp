//Moving all the zero to the right side of the array . Optimal solution
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
    int n = arr.size();
    int j = -1;
    
    for(int i=0; i<n; i++)
    {
        if(arr[i] == 0)
        {
            j=i;
        }
        break;
    }

    for(int i=j+1; i<n; i++)
    {
        if(arr[i] != 0)
        {
            swap(arr[i],arr[j]);
            j++;
        }
    }


}

int main()
{
    vector<int> arr = {1,0,2,0,0,3,4,5,0,6};
    printArr(arr);
    cout<<endl;
    moveArr(arr);
    printArr(arr);

}