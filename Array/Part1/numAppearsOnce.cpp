// Find the number that appears once, and the other numbers twice
// Input: nums = [2,2,1]
// Output: 1

#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Sustinable approach
// int singleNumber(vector<int>& arr) {
//     int n = arr.size();
//     map<int,int> mpp;

//     for(int i=0; i<n; i++)
//     {
//         mpp[arr[i]]++;
//     }

//     for(auto it: mpp)
//     {
//         if(it.second == 1)
//         {
//             return it.first;
//         }
//     }

//     return 0;
// }


// Optimal approach with XOR
int singleNumber(vector<int>& arr) {
    int n = arr.size();
    int XOR = 0;

    for(int i=0; i<n; i++)
    {
        XOR = XOR ^ arr[i];
    }

    return XOR;
        
}

int main()
{
    vector<int> arr = {2,2,1};
    vector<int> arr1 = {4,1,2,1,2};
    cout<<singleNumber(arr)<<endl;
    cout<<singleNumber(arr1)<<endl;
}