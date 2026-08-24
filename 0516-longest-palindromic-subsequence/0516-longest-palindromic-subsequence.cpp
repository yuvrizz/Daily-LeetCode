class Solution {
public:

    int helper(string& s1, string& s2, int m, int n, vector<vector<int>> &dp){

        if(m < 0 || n < 0){
            return 0;
        }

        if(dp[m][n] != -1){
            return dp[m][n];
        }

        if(s1[m] == s2[n]){
            dp[m][n] = 1 + helper(s1,s2, m-1, n-1, dp);
        }
        else{
            dp[m][n] = max(helper(s1,s2,m-1,n,dp),helper(s1,s2,m,n-1,dp));
        }

        return dp[m][n];
    }

    int longestPalindromeSubseq(string s) {

        int m = s.size();
        string s_rev = s;
        reverse(s_rev.begin(), s_rev.end());
        
        int n = m; 

        vector<vector<int>> dp(m,vector<int> (n,-1));

        return helper(s,s_rev,m-1,n-1,dp);
    }
};