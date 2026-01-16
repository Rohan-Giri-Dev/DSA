#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
    int majorityElement(vector<int> &arr){
        int n = arr.size();
        int count = 1;
        int ans = 0;

        for(int i=1; i<=n-1; i++){
            if(arr[i] == arr[i-1]){
                count++;
            }
            else{
                count = 1;
            }

            if(count > (n/2)) ans = arr[i];
        }

        return ans;
    }
};