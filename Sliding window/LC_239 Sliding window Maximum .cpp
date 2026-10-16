class Solution {
public:
     // TC -> O(nlogn) , SC-> O(n); , using heap 
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //    priority_queue<pair<int , int>>pq;
    //     int n = nums.size();
    //     vector<int>ans;
    //     for(int i = 0; i < k ; i++)pq.push({nums[i] , i});
    //     ans.push_back(pq.top().first);

    //     for(int i = k ; i < n ; i++){
    //         pq.push({nums[i] , i});
    //         while(!pq.empty() && i - pq.top().second + 1 > k)pq.pop();
    //         ans.push_back(pq.top().first);
    //     }
    //     return ans ;
    // }

    // Approach 2 using deque , TC -> O(n) , SC-> O(k)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>dq; // store index front one will give max. value
        vector<int>ans;
      
        for(int i = 0 ; i < n ; i++){
            // Remove indices outside the current window
            while (!dq.empty() && dq.front() <= i - k)  dq.pop_front();
            while(!dq.empty() && nums[dq.back()] <= nums[i])dq.pop_back();
            dq.push_back(i);
                        // Window is complete
            if (i >= k - 1) ans.push_back(nums[dq.front()]);


        }
        return ans ;
    }
};