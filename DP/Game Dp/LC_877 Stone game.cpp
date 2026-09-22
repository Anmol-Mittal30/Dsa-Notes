// TC-> O(n^2) , SC -> O(n^2)

class Solution {
public:
    int n;
    int dp[501][501];
    int solve(int i , int j , vector<int>&piles){
        if(i > j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take_first = piles[i] - solve(i+1 , j , piles);
        int take_last  = piles[j] - solve(i , j-1 , piles);
        return dp[i][j] =  max(take_first , take_last);
    }
    bool stoneGame(vector<int>& piles) {
        n = piles.size();
        memset(dp , -1 , sizeof(dp));
        int score = solve(0 , n-1 , piles);
        // i am just cal. alice - bob score
        return score >=0; // that means alice wins otherwise bob
    }
};