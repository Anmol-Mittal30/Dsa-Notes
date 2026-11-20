class Solution
{
public:
    // TC -> O(nlogn) , SC-> O(n)
    int n;
    vector<vector<int>> memo;
    int findMethod(int start, vector<int> &nums, int target)
    {
        int j = lower_bound(begin(nums) + start, end(nums), target) - begin(nums);
        if (j < n && nums[j] == target)
            return j;
        return -1;
    }
    int solve(int i, int inc, vector<int> &nums)
    {
        if (i >= n)
            return 0;
        if (memo[i][inc] != -1)
            return memo[i][inc];
        int currVal = nums[i] + inc; // 0/1
        int len = 1;
        // 1st optn find(currval + 1)
        int j = findMethod(i + 1, nums, currVal + 1);
        if (j != -1)
        {
            len = max(len, 1 + solve(j, 0, nums));
        }
        // 2nd optn // find(currval)
        j = findMethod(i + 1, nums, currVal);
        if (j != -1)
        {
            len = max(len, 1 + solve(j, 1, nums));
        }
        return memo[i][inc] = len;
    }
    int maxSelectedElements(vector<int> &nums)
    {
        n = nums.size();
        sort(begin(nums), end(nums));
        memo.assign(n + 1, vector<int>(2, -1));
        int ans = 1;

        for (int i = 0; i < n; i++)
        {
            ans = max({ans, solve(i, 0, nums), solve(i, 1, nums)});
        }
        return ans;
    }
};