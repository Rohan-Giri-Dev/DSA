class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        long long  sum = 0 , maxSum = LONG_MIN;

        for(int i = 0; i<=n-1; i++){
            sum += arr[i];

            if( sum > maxSum){
                maxSum = max(maxSum, sum);
            }

            if( sum < 0){
                sum = 0;
            }
        }

        return maxSum;
    }
};