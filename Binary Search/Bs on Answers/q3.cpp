//1482. Minimum Number of Days to Make m Bouquets

#include <iostream>
#include <vector>
#include <algorithm>
    using namespace std;

int canMakeBoq(vector<int> &bloomDay, int mid, int k){
    int bouq_cnt = 0;
    int consequitive_cnt = 0;

    for(int i = 0; i < bloomDay.size(); i++){
        if(bloomDay[i] <= mid){
            consequitive_cnt++;
        }else{
            consequitive_cnt = 0;
        }

        if(consequitive_cnt == k){
            bouq_cnt++;
            consequitive_cnt = 0;
        }
    }

    return bouq_cnt;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();

    int start_day = 0;
    int end_day = *max_element(begin(bloomDay), end(bloomDay));

    int minDays = -1; // result

    while(start_day <= end_day){
        int mid = start_day + (end_day - start_day)/2;

        if(canMakeBoq(bloomDay, mid, k) >= m){
            minDays = mid;
            end_day = mid-1;
        }else{
            start_day = mid+1;
        }
    }

    return minDays;
}