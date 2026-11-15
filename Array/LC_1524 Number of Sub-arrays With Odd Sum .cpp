class Solution {
public:
    //  TC -> O(n) , SC-> O(1)
    // oddcnt + evenCnt = odd [always] so when sum odd ; add evenCnt and vice versa
    const int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int ans = 0;
        int evenCnt = 1 , oddCnt = 0;
        for(int i = 0 ; i < n ; i++){
            sum+=arr[i];
            if(sum % 2 == 1){ // odd
                ans+=evenCnt;
                oddCnt++;
                ans %= mod;
            } else {
                ans+=oddCnt;
                evenCnt++;
                ans %= mod;
            }
        }
        return ans ;
    }
}; 