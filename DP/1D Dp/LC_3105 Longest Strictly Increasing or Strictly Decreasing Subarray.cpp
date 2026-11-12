class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        // Approach 1 - TC -> O(n) , SC-> O(n)
        //     int n = nums.size();
        //     vector<int>inc(n , 1) , dec(n , 1);
        //     int ans = 1;
        //     for(int i = 1 ; i < n ; i++){
        //         if(nums[i] > nums[i-1]) dec[i] = dec[i-1] + 1;
        //         if(nums[i] < nums[i-1]) inc[i] = inc[i-1] + 1;
        //         ans = max({ans , inc[i] , dec[i]});
        //     }
        //     return ans ;

        // Approach 2 - TC -> O(n) , SC-> O(1)
        int inc = 1, dec = 1;
        int ans = 1;
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
                dec++, inc = 1;
            else if (nums[i] < nums[i - 1])
                inc++, dec = 1;
            else
                inc = dec = 1;
            ans = max({ans, inc, dec});
        }
        return ans;
    }
};