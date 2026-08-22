class Solution {
public:
    int helper(int m, int n, vector<vector<int>> &dp, vector<vector<int>>& obstacleGrid){
        
        if(m < 0 || n < 0){
            return 0;
        }

        if(obstacleGrid[m][n] == 1){
            return 0; 
        }

        if(m == 0 && n == 0){
            return 1;
        }

        if(dp[m][n] != -1){
            return dp[m][n];
        }

        int right = helper(m,n-1,dp,obstacleGrid);
        int down = helper(m-1,n,dp,obstacleGrid);

        dp[m][n] = right + down;

        return dp[m][n];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size() - 1;
        int n = obstacleGrid[0].size() - 1;

        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return helper(m,n,dp,obstacleGrid);
    }
};