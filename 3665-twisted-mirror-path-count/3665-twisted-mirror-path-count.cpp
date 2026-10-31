class Solution {
public:

    const int MOD = 1e9 + 7;

    // right - 1 
    // down - 0
    int helper(vector<vector<int>>& grid, int prevmove, int n, int m,  vector<vector<vector<int>>> &dp){

        if(n >= grid.size() || m >= grid[0].size()){
            return 0;
        }

        if(n == grid.size()-1 && m == grid[0].size()-1){
            return 1;
        }

        if(dp[n][m][prevmove] != -1){
            return dp[n][m][prevmove];
        }

        long long right = 0;
        long long down = 0;

        if(grid[n][m] == 0){
            right = helper(grid,1,n,m+1,dp);
            down = helper(grid,0,n+1,m,dp);
        }
        else{
            if(prevmove == 1){
                down = helper(grid,0,n+1,m,dp);
            }
            else{
                right = helper(grid,1,n,m+1,dp);
            }
        }

        return dp[n][m][prevmove] = (down+right) % MOD;
    }


    int uniquePaths(vector<vector<int>>& grid) {

        int n = grid[0].size();
        int m = grid.size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int>(2,-1)));

        return helper(grid,0,0,0,dp);
    }
};