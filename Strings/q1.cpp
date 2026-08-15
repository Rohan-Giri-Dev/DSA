// 443. String Compression
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char> &chars) {
        const int n = chars.size();
        int writeIndex = 0;
        int i = 0;

        while (i < n) {
            const char currentChar = chars[i];
            int count = 0;

            // Count the current group of identical characters.
            while (i < n && chars[i] == currentChar) {
                count++;
                i++;
            }

            chars[writeIndex++] = currentChar;

            // Single characters need no count suffix.
            if (count > 1) {
                const string countString = to_string(count);
                for (const char digit : countString) {
                    chars[writeIndex++] = digit;
                }
            }
        }

        return writeIndex;
    }
};

/*
Started with the problem of compressing a string represented as a vector of characters. The goal is to modify the input vector in-place to represent the compressed version of the string and return the new length of the compressed string.
The algorithm uses a two-pointer technique. The first pointer, `i`, iterates through the input vector, while the second pointer, `index`, keeps track of the position in the vector where the next character or count should be placed.
For each unique character encountered, the algorithm counts its occurrences and updates the vector accordingly. If a character appears more than once, its count is converted to a string and added to the vector. Finally, the function returns the new length of the compressed string.
*/
