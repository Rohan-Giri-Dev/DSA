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

    reverse(s.begin(), s.end()); //meow

    long long val = stoi(s);

    return val * sum;
}

int main()
{
    int n = 10203004;

    long long ans = sumAndMultiply(n);

    cout << "Ans: " << ans;
}

/*
Here's a separate walkthrough of what this code does:

## What the function does
Given an integer `n`, it:
1. Extracts all digits of `n`, but **skips zeros**
2. Concatenates the non-zero digits back together in their original order to form a new number
3. Also computes the sum of those non-zero digits
4. Returns `(concatenated number) * (digit sum)`

## Step by step

**Digit extraction loop**
```cpp
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
```
- `num % 10` peels off the last (rightmost) digit of `num` each iteration.
- Digits come out in **reverse order** (last digit first), since that's how repeated `%10` / `/10` naturally works.
- Only non-zero digits are kept — appended to string `s` and added to `sum`. Zero digits are silently dropped from both.
- Example: `n = 10203004` → digits pulled out in order `4, 0, 0, 3, 0, 2, 0, 1` → after skipping zeros, `s` builds up as `"4"`, `"43"`, `"432"`, `"4321"` (dropping the zeros along the way), and `sum = 4+3+2+1 = 10`.

**Empty check**
```cpp
if (s.empty())
    return 0;
```
Guards against `n == 0` (or a number made entirely of zero digits, which isn't really possible for a positive int but is a safe check anyway). Without this, converting an empty string to a number below would crash.

**Reverse**
```cpp
reverse(s.begin(), s.end());
```
Since digits were collected in reverse (rightmost digit first), `s` at this point holds the digits backwards relative to the original number. Reversing puts them back in the correct left-to-right order. For `n = 10203004`, `s` becomes `"1234"`.

**Convert and combine**
```cpp
long long val = stoi(s);
return val * sum;
```
- `stoi(s)` parses the digit string into an integer. For `n = 10203004`, `val = 1234` and `sum = 10`, so the function returns `1234 * 10 = 12340`.

## One thing worth flagging
`stoi` returns an `int`, but the function's return type is `long long`. If `s` ever represents a value larger than what `int` can hold (up to ~2.1 billion), `stoi` will throw `std::out_of_range` even though `long long` could easily store the result. Using `stoll(s)` instead would match the return type and avoid that risk — same fix as in your earlier version of this problem.
*/