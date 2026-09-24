
// TC -> O(logn) , SC-> O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
     int s=0,e= nums.size()-1;
     while(s<=e)
     {
        int midd= s+(e-s)/2;
        if( (midd==0 ||nums[midd]>nums[midd-1]) && ( midd==nums.size()-1|| nums[midd]>nums[midd+1])) return midd;
        
         if( nums[midd+1]>nums[midd]) s=midd+1;
        else e= midd-1;
     }   
     return s;
    }
};