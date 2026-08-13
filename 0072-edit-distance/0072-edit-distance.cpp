class Solution {
public:
    
    int helper(int n, int m, string& word1, string& word2, vector<vector<int>>& dp){

        if(n == word1.size()){
            return word2.size()-m;
        }

        if(m == word2.size()){
            return word1.size()-n;
        }

        if(dp[n][m] != -1){
            return dp[n][m];
        }

        if(word1[n] == word2[m]){
            return helper(n+1,m+1,word1,word2,dp);
        }

        int insert = helper(n,m+1,word1,word2,dp);
        int del = helper(n+1,m,word1,word2,dp);
        int replace = helper(n+1,m+1,word1,word2,dp);

        return dp[n][m] = 1 + min({insert, del, replace});
    }

    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size(); 

        vector<vector<int>> dp (n, vector<int> (m, -1));

        return helper(0,0,word1,word2,dp);
    }
};