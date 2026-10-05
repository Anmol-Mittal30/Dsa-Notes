class Solution {
public:
    // TC -> O(n) , SC -> O(1)
    int lengthOfLongestSubstring(string s) {
        int n  = s.size();
        int i = 0 , j = 0 ;
        vector<bool>cnt(256 , 0);
        int ans = 0 ;
        while(i < n && j < n){
            while(i < j && cnt[s[j]]) {
                cnt[s[i]] = 0;
                i++;
            }
            cnt[s[j]] = 1;
            ans = max(ans , j - i + 1);
            j++;
        }
        return ans ;
    }
};