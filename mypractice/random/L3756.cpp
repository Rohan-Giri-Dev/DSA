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

/*
Overall Problem
Given a digit string s and a list of queries (each a [l, r] range), for each query you need to:

Take the substring s[l..r]
Drop all the zero digits from it, and concatenate the remaining digits into one big number (mod 1e9+7)
Multiply that number by the sum of all digits (including zeros) in s[l..r]
Return that result mod 1e9+7

Since l..r ranges can be large and there can be many queries, the code precomputes prefix arrays once (O(n)) so each query can be answered in O(1) instead of re-scanning the substring every time.
Precomputed arrays
pow10[i] — powers of 10 mod 1e9+7, i.e. pow10[i] = 10^i mod MOD. This is needed later to "shift" a number left by i decimal digits (equivalent to multiplying by 10^i) when stitching two number pieces together.
nonZeroCount[i] — count of non-zero digits in s[0..i]. This tells you how many digits will actually appear in the concatenated "non-zero number" for any prefix ending at i. It's used to know how far to shift when extracting a middle piece of that number.
numberUpTo[i] — the concatenated number formed by only the non-zero digits in s[0..i], taken mod MOD. Zero digits are skipped entirely (not even added as a "0" placeholder) — if s[i] is '0', numberUpTo[i] just carries over unchanged from numberUpTo[i-1].
digitSumUpTo[i] — plain prefix sum of digit values in s[0..i] (zeros included, since they don't affect the sum anyway).
Answering each query
For a query [l, r]:

sum — sum of digits in the range, via prefix-sum subtraction: digitSumUpTo[r] - digitSumUpTo[l-1].
numBefore — the concatenated non-zero-digit number for everything before l (i.e. s[0..l-1]). This is the "prefix" piece that needs to be peeled off from numberUpTo[r].
k — how many non-zero digits fall inside [l, r]. This tells you how many decimal digits long the range's concatenated number is, which is how far numBefore needs to be shifted to align with numberUpTo[r] before subtracting it.
x — the actual concatenated non-zero number for just the range [l, r]. The logic is: numberUpTo[r] = (numBefore shifted left by k digits) + (the range's own number). So subtracting numBefore * pow10[k] from numberUpTo[r] isolates the range's number. The + MOD) % MOD guards against negative results from modular subtraction.
result[i] — finally, x * sum mod MOD, matching the problem's requirement (product of the concatenated non-zero number and the digit sum).

Key technique
This is essentially prefix-based digit DP / rolling hash-style extraction: instead of rebuilding a number for each query from scratch, you maintain a running "encoded" value (numberUpTo) the same way you'd maintain a prefix sum, and use the "shift by known length, then subtract" trick (common in rolling hashes and number concatenation problems) to peel out just the middle slice you need — all in O(1) per query after O(n) preprocessing.
*/