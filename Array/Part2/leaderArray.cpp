/*Problem Statement: Given an array, print all the elements which are leaders.
A Leader is an element that is greater than all of the elements on its right side in the array.*/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> leadArray(vector<int> arr){

    int n =  arr.size();
    vector<int> res;

    int maxRight = arr.back();
    res.push_back(arr.back());

    for(int i=n-2; i>=0; i--){
        if(arr[i] >= maxRight ){
            res.push_back(arr[i]);
            maxRight = arr[i];
        }
    }

    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    vector<int> arr ={4,5,7,1};

    vector<int> ans = leadArray(arr);

    for(auto it : ans)
    {
        cout<<it<<" ";
    }

    return 0;
}