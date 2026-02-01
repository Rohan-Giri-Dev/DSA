#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int minPrice = prices[0];
    int profit = 0;

    for(int i = 0; i<n; i++){
        minPrice =  min(minPrice, prices[i]);
        profit  = max(profit, prices[i] - minPrice);
    }

    return profit;
}

int main()
{
    // vector<int> prices = {7, 1, 5, 3, 6, 4}; // ans 5
    vector<int> prices = {7, 6, 4, 3, 1}; // ans 0
    cout<< maxProfit(prices);
}