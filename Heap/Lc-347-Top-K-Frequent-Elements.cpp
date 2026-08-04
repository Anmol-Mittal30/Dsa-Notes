class Solution {
public:

    // ============================================================
    // Approach 1: Min Heap
    // Time  : O(n + m log k)
    // Space : O(m)
    // ============================================================

    /*
    typedef pair<int,int> P;

    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> freq;

        for(int x : nums)
            freq[x]++;

        priority_queue<P, vector<P>, greater<P>> pq;

        for(auto &it : freq)
        {
            pq.push({it.second, it.first});

            if(pq.size() > k)
                pq.pop();
        }

        vector<int> ans;

        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
    */

    // ============================================================
    // Approach 2: Bucket Sort (Optimal)
    // Time  : O(n)
    // Space : O(n)
    // ============================================================

    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> freq;

        for(int x : nums)
            freq[x]++;

        vector<vector<int>> bucket(nums.size() + 1);

        for(auto &[num , freq] : freq)
            bucket[freq].push_back(num);

        vector<int>ans;

        for(int i = nums.size(); i >= 1; i--)
        {
            for(int num : bucket[i])
            {
                ans.push_back(num);

                if(ans.size() == k)
                    return ans;
            }
        }

        return ans;
    }
};