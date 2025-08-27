#include <iostream>
#include <vector>
#include <algorithm> // for reverse, swap

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;

        // 1) find pivot
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) { ind = i; break; }
        }

        // 2) if no pivot, reverse all and return
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // 3) find rightmost element > nums[ind] and swap
        for (int i = n - 1; i > ind; --i) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // 4) reverse the suffix
        reverse(nums.begin() + ind + 1, nums.end());
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution s1;
    s1.nextPermutation(nums);
    for (int x : nums) cout << x << " "; // should print: 1 3 2
}
