#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>> &queries)
    {
        int n = s.length();

        vector<long long> digitSumUpTo(n, 0);
        vector<int> nonZeroCount(n, 0);
        vector<long long> pow10(n + 1, 0);
        vector<long long> numberUpTo(n, 0);

        // -------------------------
        // Powers of 10
        // -------------------------

        pow10[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            pow10[i] =
                (pow10[i - 1] * 10) % MOD;
        }

        // -------------------------
        // Non-zero digit prefix count
        // -------------------------

        nonZeroCount[0] = (s[0] != '0');

        for (int i = 1; i < n; i++)
        {
            int dig = s[i] - '0';

            nonZeroCount[i] =
                nonZeroCount[i - 1] + (dig != 0);
        }

        // -------------------------
        // Concatenated non-zero number
        // -------------------------

        numberUpTo[0] = s[0] - '0';

        for (int i = 1; i < n; i++)
        {

            int dig = s[i] - '0';

            if (dig != 0)
            {

                numberUpTo[i] =
                    ((numberUpTo[i - 1] * 10) + dig) % MOD;
            }
            else
            {

                numberUpTo[i] =
                    numberUpTo[i - 1];
            }
        }

        // -------------------------
        // Digit sum prefix
        // -------------------------

        digitSumUpTo[0] = s[0] - '0';

        for (int i = 1; i < n; i++)
        {

            int dig = s[i] - '0';

            digitSumUpTo[i] =
                digitSumUpTo[i - 1] + dig;
        }

        // -------------------------
        // Process queries
        // -------------------------

        int q = queries.size();

        vector<int> result(q);

        for (int i = 0; i < q; i++)
        {

            int l = queries[i][0];
            int r = queries[i][1];

            // Sum of digits in [l, r]

            long long sum =
                digitSumUpTo[r] - ((l == 0)
                                       ? 0
                                       : digitSumUpTo[l - 1]);

            // Prefix number before l

            long long numBefore =
                (l == 0)
                    ? 0
                    : numberUpTo[l - 1];

            // Number of non-zero digits in [l, r]

            int k =
                nonZeroCount[r] - ((l == 0)
                                       ? 0
                                       : nonZeroCount[l - 1]);

            // Extract concatenated number for [l, r]

            long long x =
                (numberUpTo[r] - (numBefore * pow10[k]) % MOD + MOD) % MOD;

            result[i] =
                (int)((x * sum) % MOD);
        }

        return result;
    }
};