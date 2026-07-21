// 875. Koko Eating Bananas
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    bool canEatAll(vector<int> piles, int mid, int h)
    {
        int actualHrs = 0;

        for (int &x : piles)
        {
            actualHrs += x / mid;

            if (x % mid != 0)
            {
                actualHrs++;
            }
        }

        return actualHrs <= h;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();

        int l = 1;
        int r = *max_element(begin(piles), end(piles));

        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (canEatAll(piles, mid, h))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        return l;
    }
};