//1011. Capacity To Ship Packages Within D Days
#include <iostream>
#include <vector>
#include <algorithm>
    using namespace std;

int canCarry(vector<int> &weights,int mid){
    int completeDays = 1;
    int load = 0;

    for(auto &w : weights){
        if((load + w) > mid){
            completeDays++;
            load = w;
        } else{
            load += w;
        }
    }

    return completeDays;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int sum = 0;
    for(auto &x: weights){
        sum += x;
    }
    int l = *max_element(begin(weights), end(weights));
    int r = sum;

    while(l < r){
        int mid = l + (r-l)/2;

        if ((canCarry(weights, mid)) <= days)
        {
            r = mid;
        }else{
            l = mid+1;
        }
    }

    return l;

}

int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    int result = shipWithinDays(weights, days);
    cout << "Result: " << result << endl;
    cout << "Expected: 15" << endl;

    return 0;
}