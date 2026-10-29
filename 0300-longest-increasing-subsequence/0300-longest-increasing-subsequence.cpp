class Solution {
public:

    int helper(vector<int>& nums, int idx, int prev, vector<vector<int>>& dp){

        if(idx == nums.size()){
            return 0;
        }

        if (dp[idx][prev + 1] != -1) {
            return dp[idx][prev + 1];
        }

        int include = INT_MIN;

        if(prev == -1 || nums[prev] < nums[idx]){
            include = 1 + helper(nums,idx+1,idx,dp);
        }

        int exclude = helper(nums,idx+1,prev,dp); 

        return dp[idx][prev + 1] = max(include,exclude);
    }

    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return helper(nums,0,-1,dp);
    }
};