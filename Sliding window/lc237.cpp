class Solution {
public:
    //  TC -> O(nlogn), Sc-> O(n);
    // typedef pair<int , int>P;
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     int n= nums.size();
    //     priority_queue<P>pq; // val , idx
    //     for(int i=0;i<k;i++)pq.push({nums[i] , i});
    //     vector<int>ans;
    //     ans.push_back(pq.top().first);
    //     for(int i=k; i<n; i++){
    //         pq.push({nums[i] , i});
    //         while(pq.top().second <= i-k) pq.pop();
    //         ans.push_back(pq.top().first);
    //     }
    //     return ans;

    // }

    // using deque Tc -> O(n) , Sc-> O(n);
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>dq;  // idx
        vector<int>ans;

       for(int i=0; i<n; i++){
          // outside the window
          while(!dq.empty() && dq.front() <= i-k) dq.pop_front();
          
          while(!dq.empty() && nums[dq.back()] <= nums[i])dq.pop_back();

          dq.push_back(i);
          if(i >= k-1) ans.push_back(nums[dq.front()]);
       }
       return ans;
        
    }
};