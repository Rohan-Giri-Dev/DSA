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