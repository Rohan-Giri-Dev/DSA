// 12. Integer to Roman

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        static vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        static vector<string> sym{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result= "";

        for(int i = 0; i< val.size() ; i++){
            if(num == 0) break;

            // see how many times the num is val[i]
            int times = num/val[i];

            while(times > 0){
                result += sym[i];
                times--;
            }

            // remove val from that num or remaning after remainder
            num = num%val[i];
        }

        return result;
    }
};