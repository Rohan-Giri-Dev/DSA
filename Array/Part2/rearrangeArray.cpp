#include <iostream>
#include <vector>

using namespace std;

// vector<int> rearrangeArray(vector<int>& arr) {
//     int n = arr.size();
//     vector<int> ps;
//     vector<int> ne;
//     vector<int> temp;

//     for(int i=0; i<n; i++)
//     {
//         if(arr[i] >= 0)
//         {
//             ps.push_back(arr[i]);
//         }
//         else{
//             ne.push_back(arr[i]);
//         }
//     }
//     int pos =0 , neg = 0;

//     for(int i=0; i<n; i++)
//     {
//         if( i%2 == 0)
//         {
//             temp.push_back(ps[pos++]);
//         }
//         else{
//             temp.push_back(ne[neg++]);
//         }
//     }

//     return temp;
// }
vector<int> rearrangeArray(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp;
    int posIndex = 0 , negIndex = 0;

    for(int i=0; i<n; i++)
    {
        if(arr[i] < 0)
        {
            temp[negIndex] = arr[i];
            negIndex += 2;
        }
        else{
            temp[posIndex] = arr[i];
            posIndex += 2;
        }
    }

    return temp;
        
}

int main()
{
    vector<int> arr = {3,1,-2,-5,2,-4};
    vector<int> res = rearrangeArray(arr);

    for(auto it: res)
    {
        cout<<it<<" ";
    }
}