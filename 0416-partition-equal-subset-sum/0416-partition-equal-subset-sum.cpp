class Solution {
public:

    bool helper(vector<int>& nums, vector<vector<int>>& dp, int idx, int target){

        if(target == 0){
            return true;
        }

        if(idx == 0){
            return nums[0] == target;
        }

        if(dp[idx][target] != -1){
            return dp[idx][target];
        }

        int include = 0;

        if(nums[idx] <= target){
            include = helper(nums,dp,idx-1,target-nums[idx]);
        }

        int non_include = helper(nums,dp,idx-1,target);

        dp[idx][target] = include || non_include;

        return dp[idx][target];
    }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum % 2 != 0){
            return false;
        }

        int target = sum/2;

        vector<vector<int>> dp(n,vector<int>(target + 1, -1));

        return helper(nums,dp,n-1,target);
    }
};