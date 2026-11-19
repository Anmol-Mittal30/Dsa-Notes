//  TC -> O(nlogn) , SC-> O(1)


class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums) , end(nums));
        int ans = INT_MAX;
        
        ans = min(ans , nums[n-1] - nums[2]);  // case 1 -> make 1st and 2nd equal
        ans = min(ans , nums[n-2] - nums[1]);  // case 2 -> make 1st equal to 2nd and last equal to 2nd last
        ans = min(ans , nums[n-3] - nums[0]);  // case 3 -> make last two element equal with 2nd last
        return ans ;
    }
};