class Solution {
public:
    int helper(int m, int n, vector<vector<int>>& dp, vector<vector<int>>& grid){

        if(m == 0 && n == 0){
            return grid[m][n];
        }

        if(m < 0 || n < 0){
            return INT_MAX;
        }

        if(dp[m][n] != -1){
            return dp[m][n];
        }

        int right = helper(m,n-1,dp,grid);
        int bottom = helper(m-1,n,dp,grid);

        dp[m][n] = grid[m][n] + min(right,bottom);
 
        return dp[m][n];
    }

    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size()-1;
        int n = grid[0].size()-1; 
        vector<vector<int>> dp (m+1,vector<int>(n+1,-1));

        return helper(m,n,dp,grid);
    }
};