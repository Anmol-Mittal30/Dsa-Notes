// #LeetCode 3934 – Smallest Unique Subarray

// ## #Approach : Binary Search + Rolling Hash + Sliding Window

//                -
//                Apply Binary Search on subarray length(`1` to `n`).- Use Rolling Hash to calculate subarray hashes efficiently.- Store hash frequencies using `unordered_map`.- If any hash occurs exactly once,
// try a smaller length.
// - Otherwise, search for a larger length.

// ### Complexity Analysis

// - **Time Complexity:** \(O(n \log n)\) average
// - **Space Complexity:** \(O(n)\)

// ### Key Concepts
// Binary Search on Answer, Rolling Hash, Sliding Window, Binary Exponentiation.




class Solution
    {
    public:
        //  TC -> O(nlogn) , SC-> O(n)
        typedef long long ll;
        int mod = 1e9 + 7;
        int base;
        int n;
        ll findPower(ll a, ll base)
        {
            if (base == 0)
                return 1;
            ll half = findPower(a, base / 2);
            ll ans = (half * half) % mod;
            if (base % 2 == 1)
                ans = (ans * a) % mod;
            return ans;
        }
        bool check(int size, vector<int> &nums)
        {
            ll hash = 0;
            ll p = findPower(base, size - 1);
            unordered_map<ll, int> mp;
            int i = 0, j = 0;

            while (j < n)
            {
                hash = (hash * base + nums[j]) % mod;
                if (j - i + 1 < size)
                    j++;
                else
                {
                    mp[hash]++;
                    hash = (hash - (p * nums[i]) % mod + mod) % mod;
                    i++;
                    j++;
                }
            }
            for (auto &it : mp)
            {
                if (it.second == 1)
                    return true;
            }
            return false;
            


    }
    int smallestUniqueSubarray(vector<int>& nums) {
        n = nums.size();
        base = *max_element(begin(nums) , end(nums)) + 1 ;

        int s = 1;
        int e = n;
        int ans = n;
        while(s <= e){
            int mid = s + (e-s) / 2;
            if(check(mid , nums)){  // it checks can be possible of array of mid length
                ans = mid ;
                e = mid - 1;
            } else s = mid + 1;
        }
        return ans ;

    }
    };