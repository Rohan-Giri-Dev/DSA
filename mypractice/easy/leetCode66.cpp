#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();

        vector<int> res = digits;

        if (digits[n - 1] != 9)
        {
            res[n - 1]++;
            return res;
        }
        int carry = 0;
        if (digits[n - 1] == 9)
        {
            res[n - 1] = 0;
            carry = 1;

            for (int i = n - 2; i >= 0; i--)
            {
                if (digits[i] != 9)
                {
                    res[i] += carry;
                    carry = 0;
                    break;
                }
                else
                {
                    res[i] = 0;
                    carry = 1;
                    continue;
                }
            }
        }

        if (carry == 1)
        {
            res.insert(res.begin(), carry);
        }

        return res;
    }
};