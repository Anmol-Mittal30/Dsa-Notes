class Solution {
public:
    // TC -> O(nlogn) , SC-> O(1);
    bool isPossible(vector<int>& piles, int h , int mid){
        long long  k = 0 ;
        for(auto i : piles){
            k =  k + i / mid ;
            if(i % mid) k++;
        }
        return k <= h ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1 , e = 1 ;
        for(auto i : piles) e = max(e , i);

        int ans = e ;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(isPossible(piles , h , mid)) {
                ans = mid ; 
                e = mid - 1;
            } else s = mid + 1 ;
        }
        return ans ;
    }
};