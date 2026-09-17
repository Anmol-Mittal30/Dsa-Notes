// TC -> O(n) , SC-> O(1)


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=  nums.size();
        int ans = INT_MAX;
        int sum=0 ,i =0 ;
        for(int j=0;j<n;j++) {
            sum+=nums[j];
            while(sum >= target) ans= min(ans , j-i+1) , sum-=nums[i++];
        } 
        return ans==INT_MAX?0:ans;
    }
};