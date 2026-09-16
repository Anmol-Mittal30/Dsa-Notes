
// TC -> O(n*n) , SC-> O(n*amt) + O(amt) for recursion stack
class Solution {
public:
  int n;
  int dp[301][5001];
  int solve(int i , int amt , vector<int>&coins){
    if(amt==0) return 1;
    if(i>=n) return 0;
    if(dp[i][amt]!=-1) return dp[i][amt];
    if(amt<coins[i]) return dp[i][amt] = solve(i+1 , amt , coins);

    int take= solve(i , amt-coins[i] , coins);
    int skip= solve(i+1 , amt , coins);
    return dp[i][amt]= take+skip;
  }
    int change(int amt, vector<int>& coins) {
        n= coins.size();
        memset(dp , -1 , sizeof(dp));
        return solve(0 , amt , coins);

    }
};