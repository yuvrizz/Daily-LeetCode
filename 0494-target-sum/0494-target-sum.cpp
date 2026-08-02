class Solution {
public:
    int helper(vector<int>& nums, vector<vector<int>> &dp, int idx, int target, int offset){

        if(idx == nums.size()){
            return target == 0;
        }

        if (target > offset || target < -offset){
            return 0;
        }

        int shifted = target + offset;

        if(dp[idx][shifted] != -1){
            return dp[idx][shifted];
        }

        int plus = helper(nums,dp,idx+1,target - nums[idx],offset);
        int minus = helper(nums,dp,idx+1,target + nums[idx],offset);

        dp[idx][shifted] = plus + minus;

        return dp[idx][shifted];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if(abs(target) > totalSum){
            return 0;
        }

        int offset = totalSum;

        vector<vector<int>> dp(n,vector<int>(2*totalSum + 1,-1));

        return helper(nums,dp,0,target,offset);
    }
};