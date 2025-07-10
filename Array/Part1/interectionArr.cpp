// Finding the intersection of array 
#include <iostream>
#include <vector>
using namespace std;

vector<int> intersectionArr(vector<int> arr1, vector<int> arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    vector<int> ans;
    int visited[m] = {0};

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(arr1[i] == arr2[j] && visited[j] == 0)
            {
                ans.push_back(arr1[i]);
                visited[j]= 1;
                break;
            }

            if(arr2[j] > arr1[i]) break;
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