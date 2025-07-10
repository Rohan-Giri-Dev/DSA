// Finding the intersection of array 
#include <iostream>
#include <vector>
using namespace std;

vector<int> intersectionArr(vector<int> A, vector<int> B)
{
    int n = A.size();
    int m = B.size();
    int i = 0;
    int j = 0;
    vector<int> ans;

    while( i < n && j < m)
    {
        if( A[i] < B[j])
        {
            i++;
        }
        else if (B[j] < A[i])
        {
            j++;
        }
        else
        {
            ans.push_back(A[i]);
            i++;
            j++;
        }
        
    }

    return ans;
}

int main()
{
    vector<int> A = {1,2,2,3,4,5};
    vector<int> B = {2,3,4,5,6,7};

    vector<int> ans = intersectionArr(A,B);
    for(auto it : ans)
    {
        cout<<it<<" ";
    }
}