#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void solution(vector<int> arr,int &secondMin, int &secondMax)
{
    int n = arr.size();
    // smallest so far
    long long mn = INT_MAX;
    long long smn = INT_MAX;

    // largest
    long long mx = INT_MIN;
    long long smx = INT_MIN;

    for(int x: arr){
        // x is smaller then mn
        // so 2nd smallest(smn) becomes the smallest(mn)
        // and smallest becmes the x
        if( x < mn){
            smn = mn;
            mn = x;
        }
        //x not euqal mn and x small then 2nd smallest
        else if(x != mn && x < smn){
            smn = x;
        }

        // x is grater then mx(greatest)
        if(x > mx){
            smx = mx;
            mx = x;
        }
        // x not equals greatest(mx) && x greater then 2nd greatest(smx)
        else if( x != mx && x > smx){
            smx = x;
        }

        if(smn == LLONG_MAX || smx == LLONG_MIN) return;

        secondMin = int(smn);
        secondMax = int(smx);
    }
    cout<<"Second smallest: "<<smn<<endl;
    cout<<"Second largest: "<<smx;
}

int main(){
    vector<int> arr = {1, 2, 4, 7, 7, 5};
    int secondSmallest, secondLargest;
    solution(arr, secondSmallest, secondLargest);
}


/* int n = arr.size();
    // sort(arr.begin(), arr.end());

    // int smallest = arr[0];
    // int largest = arr[n-1];

    map<int, int> mpp;

    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }

    for(auto &p : mpp){
        cout<<p.first<<"->"<<p.second;
        cout<<endl;
    }

    auto second = mpp.begin();
    ++second;

    auto lastSecond = mpp.end();
    --lastSecond;
    --lastSecond;

    int ansSmallest = second->first;
    int ansLastSmallest = lastSecond->first;

    cout<<"Second smallest: " << ansSmallest<<'\n';
    cout<<"Second largest : " << ansLastSmallest;*/