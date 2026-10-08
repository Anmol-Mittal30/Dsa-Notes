class Solution {
public:
    // TC-> O(m + n) ,SC-> O(k) for unorderedmap  
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "" ;
        unordered_map<char , int>mp;
        for(auto i : t)mp[i]++;

        int i = 0 ;
        int idx = -1 ;
        int recq = t.size();
        int n = s.size() ;
        int maxLen = INT_MAX ;
        for(int j = 0 ; j < n  ; j++){
            if(mp[s[j]] > 0) recq--;
            mp[s[j]]--;
          
            while(recq == 0){
                if(j - i + 1 <  maxLen){
                    maxLen = j - i + 1 ;
                    idx = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0) recq++;
                i++; 
            }
        }
        if(idx == -1) return "";
        return maxLen == INT_MAX ? "" : s.substr(idx , maxLen) ;
    }
};