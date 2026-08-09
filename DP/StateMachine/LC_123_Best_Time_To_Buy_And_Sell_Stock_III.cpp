/*
=========================================================
LeetCode 123. Best Time to Buy and Sell Stock III
=========================================================

Topic:
- Dynamic Programming
- State Machine DP
- Stock DP

Approach 1: Prefix + Suffix Profit Arrays

Idea:
- pre[i]  = maximum profit from one transaction in [0...i]
- suf[i]  = maximum profit from one transaction in [i...n-1]
- Try every split point and combine both profits.

Time Complexity : O(n)
Space Complexity: O(n)

---------------------------------------------------------
Approach 2: State Machine DP (Optimized)
---------------------------------------------------------

States:

firstBuy
    = maximum profit after first buy

firstSell
    = maximum profit after first sell

secondBuy
    = maximum profit after second buy

secondSell
    = maximum profit after second sell

Transitions:

firstBuy  = max(firstBuy , -price)

firstSell = max(firstSell , firstBuy + price)

secondBuy = max(secondBuy , firstSell - price)

secondSell = max(secondSell , secondBuy + price)

Answer:
    secondSell

Time Complexity : O(n)
Space Complexity: O(1)

=========================================================
*/


class Solution {
public:
    // TC -> O(n) , Sc-> O(n)
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<int>pre(n , 0) , suf(n , 0);
    //     int mn = prices[0];
    //     for(int i=1;i<n;i++){
    //         pre[i] = max(pre[i-1] , prices[i] - mn);
    //         mn = min(mn , prices[i]);
    //     }
    //     int mx = prices[n-1];
    //     for(int i = n-2; i>=0; i--){
    //         suf[i] = max(suf[i+1] , mx - prices[i]);
    //         mx = max(mx , prices[i]);
    //     }
    //     int ans =0;
    //     for(int i=0;i<n;i++) ans = max(ans , pre[i] + suf[i]);
    //     return ans;
    // }

    // Tc -> O(n) , Sc-> O(1)
    // first Sell is profit of first transcation , second buy is remain profit after sell and buy curr stock
    // second sell is the total profit 
    int maxProfit(vector<int>& prices) {
        int firstBuy = -INT_MAX , firstSell = 0;
        int SecondBuy = -INT_MAX , SecondSell = 0; 

        for(auto& p:prices){
            firstBuy =  max(firstBuy , -p);
            firstSell = max(firstSell , firstBuy + p);
            SecondBuy = max(SecondBuy , firstSell - p);
            SecondSell= max(SecondSell , SecondBuy + p);
        } 
        return SecondSell;
    }
};