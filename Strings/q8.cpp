// 1704. Determine if String Halves Are Alike
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isVowel(char &ch)
    {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
    bool halvesAreAlike(string s)
    {
        int n = s.length();

        int mid = n / 2;

        int countL = 0;
        int countR = 0;

        int i = 0;
        int j = mid;

        while (i <= mid - 1 && j <= n - 1)
        {
            if (isVowel(s[i]))
                countL++;
            if (isVowel(s[j]))
                countR++;
            i++;
            j++;
        }

        return countL == countR;
    }
};