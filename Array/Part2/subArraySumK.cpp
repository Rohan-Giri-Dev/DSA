#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;

        int n = nums.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int sum = 0;

                for(int K=i; K<=j; K++){
                    sum += nums[K];
                }

                if(sum == k) count++;
            }
        }

        return count;
    }
};

int main(){
    vector<int> arr = {1,1,1};

    Solution s;
    int ans = s.subarraySum(arr,3);
    cout<<ans;
}