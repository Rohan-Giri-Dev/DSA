// 443. String Compression
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        
        int index = 0;
        int  i = 0;

        while( i< n){
            char curr_str = chars[i];
            int cnt = 0;

            while( i< n && chars[i]== curr_str){
                // if we find the same char in the array
                cnt++;
                i++;
            }

            // now we assign as there is no dublicate
            chars[index] = curr_str;
            index++;

            // if the cnt is greater then 1 i.e 10, 11,55 etc

            if(cnt > 1){
                // converting the count to string
                string count_str = to_string(cnt);
                for(auto &ch : count_str){
                    chars[index] = ch;
                    index++;
                }
            }

        }

        return index;
    }
};

/*
Started with the problem of compressing a string represented as a vector of characters. The goal is to modify the input vector in-place to represent the compressed version of the string and return the new length of the compressed string.
The algorithm uses a two-pointer technique. The first pointer, `i`, iterates through the input vector, while the second pointer, `index`, keeps track of the position in the vector where the next character or count should be placed.
For each unique character encountered, the algorithm counts its occurrences and updates the vector accordingly. If a character appears more than once, its count is converted to a string and added to the vector. Finally, the function returns the new length of the compressed string.
*/