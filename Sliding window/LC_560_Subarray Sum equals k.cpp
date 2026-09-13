class Solution {
public: 
    // TC -> O(n) , SC-> O(n);
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int , int >mp;
        mp[0] = 1;
        int sum = 0 ;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            sum+= nums[i];
            int rem = sum - k ;
            if(mp.find(rem)!=mp.end()) ans+=mp[rem];
            mp[sum]++;
        }
        return ans ;

    }
};