// TC -> O(2^n * n)  -> 2^n for all possible partitions and n for checking each partition , SC-> O(n) for recursion stack + O(n) for curr vector + O(n^2) for dp vector

class Solution {
public:
int n;
vector<vector<bool>>dp;
vector<vector<string>>ans;
void solve(string s, int i , vector<string>&curr){
    if(i==s.size()){
        ans.push_back(curr);
        return ;
    }

    for(int j=i;j<s.size();j++){
        if(dp[i][j]==true){
            curr.push_back(s.substr(i, j-i+1));   // do 
            solve( s, j+1 , curr);               // explore
            curr.pop_back();                    // explore 
        }
    }

}

bool isPallindrome(string s , int i , int j){
    while(i<j){
        if(s[i]!=s[j]) return false;
        j--; i++;
    }
    return true;
}
void backtracking(string s , int i  , vector<string>&curr){
    if(i==s.size()){
        ans.push_back(curr);
        return ;
    }

    for(int j= i; j<s.size();j++){
        if(isPallindrome(s , i , j)) {
            curr.push_back(s.substr(i , j-i+1));
            backtracking(s, j+1 , curr);
            curr.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
       n= s.size();
    //    dp.resize(n, vector<bool>(n,0)); 
    //    Blueprint Approach 
    //    for(int i=0;i<n;i++) dp[i][i]=1;  // single char pall. hota hai 

    //    for(int l=2;l<=n;l++){
    //     for(int i=0;i<=n-l;i++){
    //         int j= i+l-1;
    //         if(s[i]==s[j]){
    //             if(l==2) dp[i][j]=1; //    ex-> 'aa' s[0]==s[1]
    //             else dp[i][j]= dp[i+1][j-1]?1:0;  // i+1 se j-1 tk pall hai toh true hoga 
    //         }
    //     }
    //    }

    //    vector<string>curr;
    //    solve(s , 0 , curr);  // cover all possibilities    dp approach  
    //    return ans;  

       vector<string>curr;
       backtracking(s , 0 , curr);                     // backtracking
       return ans;  



    }
};