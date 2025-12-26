#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void solution(vector<int> arr)
{
    int n = arr.size();
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
    cout<<"Second largest : " << ansLastSmallest;

}

int main(){
    vector<int> arr = {1, 2, 4, 7, 7, 5};
    solution(arr);
}