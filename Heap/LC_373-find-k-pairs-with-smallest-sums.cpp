class Solution {
public:

     // Optimized: Min Heap
    // TC -> O(k log(min(n1, k))) ,  SC -> O(min(n1, k))
    typedef pair<int , pair<int , int>> P;
   
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        priority_queue<P , vector<P> , greater<>> pq;  // min heap

         // Push the first pair from each row
        for(int i =0;i<min(n1 , k); i++){
            int sum = nums1[i] + nums2[0];
            pq.push({sum , {i , 0}}); // sum , {i[0] , i[1]}
        }

        vector<vector<int>>ans;
        while(k > 0){
            auto [sum , x] = pq.top();
            auto [i , j] = x;
            pq.pop();
            ans.push_back({nums1[i] , nums2[j]});
           // Move to the next element in the same row
            if(j+1 < n2){
                int sum = nums1[i] + nums2[j+1];
                pq.push({sum , {i , j+1}});
            }
         k-- ;
        }
        return ans;

    }
};