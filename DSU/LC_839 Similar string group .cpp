class Solution {
public:
    // TC -> O(n^2 *L) , SC-> O(n)
    bool similar(string a , string b){
        int diff = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i])diff++;
        }
        return diff <=2;
    }
    void dfs(vector<bool>&visit , vector<string>&strs , int i ){
        visit[i] = true ; 
        for(int j = 0 ; j < strs.size(); j++){
             if(!visit[j] && similar(strs[i] , strs[j])){
                dfs(visit , strs , j);
             }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size() ;
        vector<bool>visit(n , 0);  
        int grp = 0; 
        for(int i = 0 ; i < n; i++){
            if(!visit[i])grp++ , dfs(visit , strs , i);
        }
        return grp ;
    }
};