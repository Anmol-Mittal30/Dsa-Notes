    // TC -> O(n) < SC-> O(1)
    // int longestValidParentheses(string s) {
    //     int n = s.size();
    //     int open = 0 , close = 0;
    //     int ans = 0 ;
    //     // left to right
    //     for(int i = 0 ; i < n ; i++){
    //         if(s[i] == '(') open++;
    //         else close++;

    //         if(open == close) ans = max(ans , open + close);
    //         else if(close > open) open = close = 0;
    //     }

    //     open = close = 0;
    //     // right to left
    //      for(int i = n-1 ; i >= 0 ; i--){
    //         if(s[i] == '(') open++;
    //         else close++;

    //         if(open == close) ans = max(ans , open + close);
    //         else if(open > close) open = close = 0;
    //     }

    //     return ans ;
    // }