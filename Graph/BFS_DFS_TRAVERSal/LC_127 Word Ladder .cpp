
// TC -> O(n * m * 26) , SC -> O(n) , n = size of wordList , m = size of each word

class Solution {
public:
    typedef pair<string , int>P; // {str , count to convert }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<P>q;
        int n = beginWord.size();
        unordered_set<string>st(begin(wordList) , end(wordList));
        q.push({beginWord , 1});
        while(!q.empty()){
           int sz = q.size();
           while(sz--){
             auto [word , cnt] = q.front();
             q.pop();
             if(word == endWord) return cnt ;
             for(int i = 0 ; i < n ; i++){
                 char original = word[i];
                  for(int j = 0 ; j < 26; j++){
                    word[i] = j + 'a';
                    if(st.count(word)){
                        q.push({word , cnt + 1});
                        st.erase(word);
                    }
                  }
                  word[i] = original;
             }
           }
        }
        return 0 ;
        
    }
};