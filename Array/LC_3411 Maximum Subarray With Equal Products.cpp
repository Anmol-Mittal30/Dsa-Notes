
// TC -> (O(n^2log m)) , SC -> O(1) , where m is the maximum element in the array

class Solution {
public:
    typedef long long ll;

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        ll mx = *max_element(nums.begin(), nums.end());

        ll globalLCM = 1;
        for (int x : nums) {
            globalLCM = lcm(globalLCM, (ll)x);
        }

        ll limit = mx * globalLCM;

        for (int i = 0; i < n; i++) {

            ll pro = 1, l = 1;
            int g = 0;

            for (int j = i; j < n; j++) {

                int x = nums[j];

                // Prevent overflow
                if (pro > limit / x) break;

                pro *= x;
                g = gcd(g, x);
                l = l / gcd(l, (ll)x) * x;

                if (pro == g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
