// LeetCode 1011 - Capacity To Ship Packages Within D Days
// Topic: Binary Search on Answer
// Difficulty: Medium

/*
Intuition:
- We need the minimum ship capacity that allows shipping all packages within 'days'.
- Capacity can range from max(weights) to sum(weights).
- Binary search on capacity.
- For a fixed capacity, greedily simulate shipping and count required days.

Time Complexity: O(n * log(sum(weights)))
Space Complexity: O(1)
*/


class Solution {
public:
    bool possible(int mid , vector<int>&wt , int days){
        int day =1;
        int curr =0;
        for(auto i:wt){
            if(curr + i <= mid) curr+=i ;
            else curr = i, day++;
        }
        return day<=days;
    }
    int shipWithinDays(vector<int>& wt, int days) {
        int s = *max_element(begin(wt) , end(wt));
        int e = 1e8;
        int ans = e;
        while(s<=e){
            int  mid = s +(e-s)/2;
            if(possible(mid , wt , days)){
                ans = mid;
                e = mid-1;
            } else s= mid+1;
        }
        return ans;
    }
};