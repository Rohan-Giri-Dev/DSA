// 1011. Capacity To Ship Packages Within D Days
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given a candidate ship capacity 'mid', simulate loading packages day by day
// and return how many days it actually takes.
int canCarry(vector<int> &weights, int mid)
{
    int completeDays = 1; // we're always on at least day 1
    int load = 0;         // how much weight the ship is currently carrying today

    for (auto &w : weights)
    {
        if ((load + w) > mid)
        {
            // adding this package would exceed today's capacity ->
            // start a new day, and this package becomes today's first load
            completeDays++;
            load = w;
        }
        else
        {
            // still fits within today's capacity, so add it to today's load
            load += w;
        }
    }

    return completeDays;
}

int shipWithinDays(vector<int> &weights, int days)
{
    // Total sum of all weights, used as the upper bound of the search space
    // (a ship this big could carry everything in a single day)
    int sum = 0;
    for (auto &x : weights)
    {
        sum += x;
    }

    // Search space for the capacity:
    // Smallest possible capacity is the heaviest single package
    // (the ship must at least be able to hold the biggest item).
    // Largest useful capacity is the total sum (finishes in 1 day).
    int l = *max_element(begin(weights), end(weights));
    int r = sum;

    // Binary search for the smallest capacity that ships everything within 'days'.
    // Valid because as capacity increases, the days needed only decreases or
    // stays the same -- classic "binary search on the answer."
    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if ((canCarry(weights, mid)) <= days)
        {
            // This capacity works (finishes within the day limit).
            // It might not be the smallest that works though, so keep mid
            // as a valid candidate and keep searching the left half.
            r = mid;
        }
        else
        {
            // This capacity needs too many days -- doesn't satisfy the limit.
            // Any capacity <= mid would only need the same or more days,
            // so we can safely rule out mid and everything below it.
            l = mid + 1;
        }
    }

    // l == r here, and it's the smallest capacity that ships within 'days' days.
    return l;
}

int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    int result = shipWithinDays(weights, days);
    cout << "Result: " << result << endl; // 15
    cout << "Expected: 15" << endl;

    return 0;
}