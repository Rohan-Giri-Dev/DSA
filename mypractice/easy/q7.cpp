//Find union of an array
#include <iostream>
#include <vector>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    vector<int> res;

    int i = 0;
    int j = 0;

    while(i <n && j < m){
        if(arr1[i] < arr2[j]){
            if (res.empty() || res.back() != arr1[i])
            {
                res.push_back(arr1[i]);
            }
            i++;
        }
        else if(arr2[j] < arr1[i]){
            if (res.empty() || res.back() != arr2[j])
            {
                res.push_back(arr2[j]);
            }
            j++;
        }
        else if(arr1[i] == arr2[j]){
            if(res.empty() || res.back() != arr1[i] || res.back() != arr2[j]){
                res.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    // push rest of the elements

    while (i < n)
    {
        if (res.empty() || res.back() != arr1[i])
        {
            res.push_back(arr1[i]);
        }
        i++;
    }

    while (j < m)
    {
        if (res.empty() || res.back() != arr2[j])
        {
            res.push_back(arr2[j]);
        }
        j++;
    }
    
    return res;

}

int main(){
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {2, 3, 4, 4, 5, 6, 7};

    int n = 5, m = 7;

    vector<int> ans = findUnion(arr1, arr2, n, m);

    for(auto &x : ans){
        cout<<x<<" ";
    }

}