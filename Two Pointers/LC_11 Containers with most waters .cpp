// TC -> O(n) , SC-> O(1);


class Solution {
public:
    int maxArea(vector<int>& h) {
         int n= h.size();
        int ans=0;
        int i=0 , j= n-1;
        while(i<j){
             int l= min(h[i] , h[j]);
             int b= j-i;
             ans = max(ans , l*b);
            if(h[i] <= h[j]) {
               i++ ;
            } else j--;
        }
        return ans;
    }
};