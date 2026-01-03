#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void moveZeros(vector<int> &arr){
    int n = arr.size();
    vector<int> temp;
    int count = 0;

    for(int i=0; i<=n-1; i++){
        if(arr[i] != 0){
            temp.push_back(arr[i]);
        }else{
            count++;
        }
    }

    temp.insert(temp.end(), count, 0);

    // arr = temp;

    for(auto &x : temp){
        cout<<x << " ";
    }
}

int main()
{
    vector<int> arr = {0, 1, 0, 3, 12};
    moveZeros(arr);
}