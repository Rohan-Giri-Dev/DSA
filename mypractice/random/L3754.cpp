#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long long sumAndMultiply(int n)
{
    int num = n;

    string s;
    int sum = 0;

    while (num > 0)
    {
        int dig = num % 10;

        if (dig != 0)
        {
            s += to_string(dig);
            sum += dig;
        }

        num /= 10;
    }

    if (s.empty())
        return 0;

    reverse(s.begin(), s.end());

    long long val = stoi(s);

    return val * sum;
}

int main()
{
    int n = 10203004;

    long long ans = sumAndMultiply(n);

    cout << "Ans: " << ans;
}