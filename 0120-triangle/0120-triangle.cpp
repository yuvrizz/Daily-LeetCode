class Solution {
public:

    int helper(int height, int i,vector<vector<int>>& dp, vector<vector<int>>& triangle){

        if(height == triangle.size()){
            return 0;
        }

        if(dp[height][i] != INT_MAX){
            return dp[height][i];
        }

        int sameidx = helper(height+1, i,dp,triangle);
        int diffidx = helper(height+1, i+1, dp, triangle); 

        dp[height][i] = triangle[height][i] + min(sameidx,diffidx);

        return dp[height][i];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        
        int height = triangle.size() - 1; 
        vector<vector<int>> dp(height+1, vector<int>(height+1,INT_MAX));

        return helper(0,0,dp,triangle);
    }
};