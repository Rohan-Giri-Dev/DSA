// 1482. Minimum Number of Days to Make m Bouquets

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given a candidate number of days ("mid"), figure out how many bouquets
// we CAN make if we only pick flowers that have bloomed by then.
// A bouquet needs exactly k adjacent (consecutive-in-the-array) flowers
// that have all bloomed by "mid" days.
int canMakeBoq(vector<int> &bloomDay, int mid, int k)
{
    int bouq_cnt = 0;         // total bouquets we can form with this many days
    int consequitive_cnt = 0; // running count of adjacent bloomed flowers

    for (int i = 0; i < bloomDay.size(); i++)
    {
        if (bloomDay[i] <= mid)
        {
            // this flower has bloomed by day "mid" -> extend the streak
            consequitive_cnt++;
        }
        else
        {
            // not bloomed yet -> streak of adjacent usable flowers breaks
            consequitive_cnt = 0;
        }

        if (consequitive_cnt == k)
        {
            // we've got exactly k adjacent bloomed flowers -> one bouquet done
            bouq_cnt++;
            // reset so the next k flowers start a fresh bouquet
            // (a flower can't be reused across bouquets)
            consequitive_cnt = 0;
        }
    }

    return bouq_cnt; // how many bouquets are possible with "mid" days
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();

    // Search space: the answer (min days) has to lie between the earliest
    // possible bloom day (0, meaning nothing may have bloomed) and the
    // last flower's bloom day (worst case, wait for everything to bloom).
    int start_day = 0;
    int end_day = *max_element(begin(bloomDay), end(bloomDay));

    int minDays = -1; // stores the best (smallest) valid day count found so far

    // Binary search on the answer: "days" is monotonic here — if X days is
    // enough to make m bouquets, then any day > X is also enough.
    // We're hunting for the smallest such X.
    while (start_day <= end_day)
    {
        int mid = start_day + (end_day - start_day) / 2; // candidate day count

        if (canMakeBoq(bloomDay, mid, k) >= m)
        {
            // "mid" days is enough -> record it, then try to do better (fewer days)
            minDays = mid;
            end_day = mid - 1;
        }
        else
        {
            // "mid" days isn't enough -> need more days, search the right half
            start_day = mid + 1;
        }
    }

    return minDays;
}