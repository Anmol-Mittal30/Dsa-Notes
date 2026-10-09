
class Solution {
public:
    // TC -> O(n) , SC-> O(1);
    typedef long long ll;
    int myAtoi(string s) {
        int n = s.size();
        int sign = 0 ;
        int i = 0;
        while(i < n && s[i] == ' ')i++;

        if(s[i] == '-')sign = 1 , i++;
        else if(s[i] == '+') i++;

        ll ans = 0;
        while(i < n && s[i] == '0')i++;

        while(i <  n && s[i] >= '0' && s[i] <= '9'){
            if(ans > INT_MAX){
                if(sign) return INT_MIN;
                return INT_MAX;
            }
            ans = ans*10 + s[i] -'0';
            i++;
        }
        if(sign) ans*= -1 ;    // if sign -ve make whole into -ve
        if(ans < INT_MIN) return INT_MIN;
        if(ans > INT_MAX) return INT_MAX;

        return ans ;

    }
};