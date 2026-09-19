// TC -> O(n*klogk) , SC-> O(n*k) where n is the number of strings and k is the maximum length of a string

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string , vector<string>>mp;
        for(auto i:strs){
            string k = i;
            sort(begin(k) , end(k));
            mp[k].push_back(i);
        }
        for(auto i:mp)ans.push_back(i.second);
        return ans;
    }
};