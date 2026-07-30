// 875. Koko Eating Bananas
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Checks if Koko can finish ALL piles within 'h' hours
    // if she eats at a fixed speed of 'mid' bananas/hour.
    // This is the "feasibility check" used by binary search.
    bool canEatAll(vector<int> piles, int mid, int h)
    {
        int actualHrs = 0; // total hours needed at this eating speed

        for (int &x : piles)
        {
            // full hours needed to finish this pile
            actualHrs += x / mid;

            // if there's a remainder, she needs one more (partial) hour
            // to finish the rest of this pile
            if (x % mid != 0)
            {
                actualHrs++;
            }
        }

        // feasible only if total hours needed doesn't exceed the limit
        return actualHrs <= h;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size(); // (unused, but represents number of piles)

        // Search space for eating speed:
        // lowest possible speed is 1 banana/hour
        int l = 1;
        // highest useful speed is the largest pile
        // (eating faster than the biggest pile gives no benefit)
        int r = *max_element(begin(piles), end(piles));

        // Binary search on the answer: find the minimum speed
        // for which canEatAll(piles, speed, h) returns true
        while (l < r)
        {
            int mid = l + (r - l) / 2; // candidate eating speed

            if (canEatAll(piles, mid, h))
            {
                // mid works, so try an even smaller speed
                // (keep mid in range since it might be the answer)
                r = mid;
            }
            else
            {
                // mid is too slow, need to eat faster
                l = mid + 1;
            }
        }

        // l == r here: the smallest speed that satisfies the condition
        return l;
    }
};