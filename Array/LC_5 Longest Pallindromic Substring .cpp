
class Solution {
public:
    //  Approach 1 - expand around centre 
    // int n;
    // int maxi = 1 , idx = 0;
    // void expand(int i , int j , string &s){
    //     while(i>=0 && j<n && s[i]==s[j]){
    //         if(j-i+1 >= maxi) maxi = j-i+1 , idx = i;
    //         i-- , j++;
    //     }
    // }
    // string longestPalindrome(string s) {
    //     n= s.size();
    //    for(int i=0;i<n; i++){
    //         expand(i , i , s);
    //         expand(i , i+1 , s);

    //     }
    //     return s.substr(idx , maxi);
    // }

    // Approach 2 using blue print of dp of pall
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>>dp(n , vector<int>(n , 0));
        for(int i=0;i<n;i++) dp[i][i] = 1;

        int maxi = 1 , idx = 0;
        for(int l=2;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                int j= i+l-1;
                if(l==2 && s[i]== s[j])dp[i][j] = 2;
                if(s[i]==s[j] && dp[i+1][j-1]) dp[i][j] = 2+ dp[i+1][j-1];

                if(dp[i][j] > maxi) maxi = dp[i][j] , idx = i ;
            }
        }
        return s.substr(idx , maxi);

    }
};