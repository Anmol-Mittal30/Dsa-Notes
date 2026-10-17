class Solution
{
public:
    // TC -> O(nlogn) , SC -> O(n + u) , // where u goes upto 1e5+1
    typedef long long ll;
    const int mod = 1e9 + 7;
    vector<ll> sqSumSegTree;
    vector<ll> sumSegTree;
    vector<ll> lazyTree;
    int n;
    void lazyAddition(int i, int l, int r, int val)
    {
        int len = r - l + 1;
        sqSumSegTree[i] += 2 * val * sumSegTree[i] + len * val * val;
        sumSegTree[i] += (len * val);
    }

    void updateRange(int start, int end, int i, int l, int r, int val)
    {
        if (lazyTree[i] != 0)
        {
            lazyAddition(i, l, r, lazyTree[i]);

            if (l != r)
            {
                lazyTree[2 * i + 1] += lazyTree[i]; // update left and right node
                lazyTree[2 * i + 2] += lazyTree[i];
            }
            lazyTree[i] = 0;
        }
        // out of range
        if (l > end || r < start || l > r)
        {
            return;
        }
        // completely within range
        if (start <= l && r <= end)
        {
            lazyAddition(i, l, r, val);
            if (l != r)
            {
                lazyTree[2 * i + 1] += val; // update left and right node
                lazyTree[2 * i + 2] += val;
            }
            return;
        }

        int mid = l + (r - l) / 2;
        updateRange(start, end, 2 * i + 1, l, mid, val);
        updateRange(start, end, 2 * i + 2, mid + 1, r, val);

        sumSegTree[i] = sumSegTree[2 * i + 1] + sumSegTree[2 * i + 2];
        sqSumSegTree[i] = sqSumSegTree[2 * i + 1] + sqSumSegTree[2 * i + 2];
    }

    int sumCounts(vector<int> &nums)
    {
        n = nums.size();
        sqSumSegTree.assign(4 * n, 0);
        sumSegTree.assign(4 * n, 0);
        lazyTree.assign(4 * n, 0);

        vector<int> lastSeenIdx(1e5 + 1, -1);
        ll ans = 0;

        for (int i = 0; i < n; i++)
        {
            int start = lastSeenIdx[nums[i]] + 1;
            int end = i;
            updateRange(start, end, 0, 0, n - 1, 1);

            ans = (ans + sqSumSegTree[0]) % mod;
            lastSeenIdx[nums[i]] = i;
        }

        return ans;
    }
};