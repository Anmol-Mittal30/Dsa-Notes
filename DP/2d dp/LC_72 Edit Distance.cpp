class Solution {
public:
    // TC -> O(n*m) , SC-> O(n*m)
    int n,m;
    int dp[501][501];
    int solve(string &s , string &t , int n , int m){
        if(n==0) return m;
        if(m==0) return n;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n-1]==t[m-1]) return dp[n][m] = solve(s , t , n-1 , m-1);
        int insert = solve(s , t , n , m-1);
        int Delete = solve(s , t , n-1 , m);
        int replace= solve(s , t , n-1 , m-1);
        return dp[n][m] =  1 + min({insert , Delete , replace});
    }
    int minDistance(string s, string t) {
        n= s.size();
        m= t.size();
        memset(dp , -1 , sizeof(dp));
        return solve(s , t , n , m);
    }
};