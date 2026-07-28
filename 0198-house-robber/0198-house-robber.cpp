class Solution {
public:

    int helper(vector<int>& nums,int n, vector<int>& dp){

        if(dp[n] != -1){
            return dp[n];
        }

        int rob = helper(nums,n-2,dp) + nums[n];
        int not_rob = helper(nums,n-1,dp);

        dp[n] = max(rob, not_rob);

        return dp[n];
    }

    int rob(vector<int>& nums) {

        int n = nums.size();
        vector dp(n,-1);

        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);

        return helper(nums, n-1, dp);
    }
};