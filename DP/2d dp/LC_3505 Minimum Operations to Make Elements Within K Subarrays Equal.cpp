class Solution
{
public:
    multiset<int> left, right;
    long long leftSum = 0, rightSum = 0;

    void add(int num)
    {
        if (left.empty() || num <= *left.rbegin())
        {
            left.insert(num);

            leftSum += num;
        }
        else
        {
            right.insert(num);

            rightSum += num;
        }

        balance();
    }

    void remove(int num)
    {
        if (left.find(num) != left.end())
        {
            left.erase(left.find(num));

            leftSum -= num;
        }
        else
        {
            right.erase(right.find(num));

            rightSum -= num;
        }

        balance();
    }

    void balance()
    {
        while (left.size() > right.size() + 1)
        {
            int num = *left.rbegin();

            left.erase(left.find(num));
            right.insert(num);

            leftSum -= num;
            rightSum += num;
        }

        while (left.size() < right.size())
        {
            int num = *right.begin();

            right.erase(right.find(num));
            left.insert(num);

            rightSum -= num;
            leftSum += num;
        }
    }

    long long getCost()
    {
        int median = *left.rbegin();

        long long cost = (1LL * median * left.size() - leftSum) + (rightSum - 1LL * median * right.size());

        return cost;
    }

    long long minOperations(vector<int> &nums, int x, int k)
    {
        int n = nums.size();

        vector<long long> cost;

        int l = 0, r = 0;

        while (r < n)
        {
            add(nums[r]);

            if (r - l + 1 == x)
            {
                cost.push_back(getCost());

                remove(nums[l]);
                l++;
            }

            r++;
        }

        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 1e18));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                dp[i][j] = dp[i - 1][j];

                if (i >= x)
                {
                    dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + cost[i - x]);
                }
            }
        }

        return dp[n][k];
    }
};