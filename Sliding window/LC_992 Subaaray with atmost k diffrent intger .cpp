
// TC ->O(n) , SC-> O(n)

class Solution {
public:
    int n;
    int Atmost(vector<int>&nums , int k){
        unordered_map<int , int>mp;
        int total=0;
        int i=0 , j=0;
        while(j<n){
            mp[nums[j]]++;
            while(j< n && mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            total+= (j-i+1);
            j++;
        }
        return total;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // atmost(k)-> cnt all subarray having element <=k 
        // so simmply allsubaaray(k) - allsubaray(k-1) -> return all araay having distinct size ==k
        n= nums.size();
        return Atmost(nums , k) - Atmost(nums , k-1);  
    }
};