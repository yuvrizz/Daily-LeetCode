class Solution {
public:

    int dp[71][71][71];

    int helper(vector<vector<int>>& grid, int row, int c1, int c2){

        if(row >= grid.size()){
            return 0;
        }

        if(dp[row][c1][c2] != -1){
            return dp[row][c1][c2];
        }

        int cherry = grid[row][c1];

        if(c1 != c2){
            cherry += grid[row][c2];
        }

        int ans = 0;
        int n = grid[0].size();

        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){

                int newRow = row+1;
                int new_c1 = c1 + i; 
                int new_c2 = c2 + j; 

                if(new_c1 >= 0 && new_c1 < n && new_c2 >= 0 && new_c2 < n){
                    ans = max(ans,helper(grid,newRow, new_c1, new_c2));
                }
            }
        }

        return dp[row][c1][c2] = cherry + ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return helper(grid,0,0,n-1);
    }
};