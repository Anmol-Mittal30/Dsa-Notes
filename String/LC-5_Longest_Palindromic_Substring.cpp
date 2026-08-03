/*
==========================================================
LeetCode 5. Longest Palindromic Substring
Topic: String | Dynamic Programming | Two Pointers

Approach 1: Expand Around Center
--------------------------------
Intuition:
- Every palindrome has a center.
- The center can be:
    1. One character (odd length)
    2. Between two characters (even length)
- Expand from every possible center while characters match.

Time Complexity:
O(n²)

Space Complexity:
O(1)

==========================================================

Approach 2: Dynamic Programming
-------------------------------
Intuition:
- Let dp[i][j] represent the length of the palindrome
  formed by substring s[i...j].
- If the first and last characters are equal and the
  inside substring is also a palindrome, then:

        dp[i][j] = dp[i+1][j-1] + 2

- Handle length = 2 separately.

Time Complexity:
O(n²)

Space Complexity:
O(n²)

==========================================================
*/
// Approach 1 using Expand Around Center
  int n;
    int maxi = 1 , idx = 0;
    void expand(int i , int j , string &s){
        while(i>=0 && j<n && s[i]==s[j]){
            if(j-i+1 >= maxi) maxi = j-i+1 , idx = i;
            i-- , j++;
        }
    }
    string longestPalindrome(string s) {
        n= s.size();
       for(int i=0;i<n; i++){
            expand(i , i , s);
            expand(i , i+1 , s);

        }
        return s.substr(idx , maxi);
    }

// Approach 2 using Dynamic Programming

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)  dp[i][i] = 1;

        int maxi = 1, idx = 0;

        for (int len = 2; len <= n; len++) {
             for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                if (len == 2 && s[i] == s[j])  dp[i][j] = 2;

                if (s[i] == s[j] && dp[i + 1][j - 1])  dp[i][j] = dp[i + 1][j - 1] + 2;

                if (dp[i][j] > maxi) {
                    maxi = dp[i][j];
                    idx = i;
                }
            }
        }

        return s.substr(idx, maxi);
    }
};