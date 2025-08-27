#include <iostream>
#include <vector>
using namespace std;

vector<int> leadArray(vector<int> arr){

    int n =  arr.size();
    vector<int> temp;

    int sum = 0;

    for(int i=0; i<n; i++)
    {
        if(sum<0) break;

        for(int i=0; i<n; i++)
        {
            sum += arr[i];

            temp.push_back(arr[i]);
        }
    }

    return temp;
}

int main()
{
    vector<int> arr ={4, 7, 1, 0};

    vector<int> ans = leadArray(arr);

    for(auto it : arr)
    {
        cout<<it<<" ";
    }

    return 0;
}