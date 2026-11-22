//  TC -> O(n) , SC -> O(1)

class Solution
{
public:
    bool checkString(string s)
    {
        // Approach 1
        // return s.find("ba") == -1;

        // Approach 2
        int firstb = -1, lasta = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a')
                lasta = i;
            if (firstb == -1 && s[i] == 'b')
                firstb = i;
        }
        if (lasta < firstb || lasta == -1 || firstb == -1)
            return true;

        return false;
    }
};