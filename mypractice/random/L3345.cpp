// 3345. Smallest Divisible Digit Product I
#include <iostream>
#include <string>
using namespace std;



class Solution
{
public:
    bool isDivisible(int mid, int t)
    {
        string str = to_string(mid);
        long long product = 0;
        for (auto x : str)
        {
            product *= (x - '0');
        }

        return product % t == 0;
    }
    int smallestNumber(int n, int t)
    {
        int l = n;
        int r = 100;

        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (isDivisible(mid, t)){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return l;
    }
};

int main()
{
    Solution sol;

    int n1 = 10, t1 = 2;
    cout << "Test 1: " << sol.smallestNumber(n1, t1) << " (Expected: 10)" << endl;

    int n2 = 15, t2 = 3;
    cout << "Test 2: " << sol.smallestNumber(n2, t2) << " (Expected: 16)" << endl;

    return 0;
}