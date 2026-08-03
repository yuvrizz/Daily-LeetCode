// class Solution {
// public:
//     int helper(vector<int>& nums, vector<vector<int>> &dp, int idx, int target, int offset){

//         if(idx == nums.size()){
//             return target == 0;
//         }

//         if (target > offset || target < -offset){
//             return 0;
//         }

//         int shifted = target + offset;

//         if(dp[idx][shifted] != -1){
//             return dp[idx][shifted];
//         }

//         int plus = helper(nums,dp,idx+1,target - nums[idx],offset);
//         int minus = helper(nums,dp,idx+1,target + nums[idx],offset);

//         dp[idx][shifted] = plus + minus;

//         return dp[idx][shifted];
//     }

//     int findTargetSumWays(vector<int>& nums, int target) {
        
//         int n = nums.size();
//         int totalSum = accumulate(nums.begin(), nums.end(), 0);

//         if(abs(target) > totalSum){
//             return 0;
//         }

//         int offset = totalSum;

//         vector<vector<int>> dp(n,vector<int>(2*totalSum + 1,-1));

//         return helper(nums,dp,0,target,offset);
//     }
// };


// Partition sum concept.


class Solution {
public:
    int helper(vector<int>& nums, vector<vector<int>>& dp, int idx, int sum){

        if(idx == 0){
            if(sum == 0 && nums[0] == 0){
                return 2;
            }    
            if(sum == 0 || sum == nums[0]){
                return 1;
            }     
            return 0;
        }

        if(dp[idx][sum] != -1){
            return dp[idx][sum];
        }
            
        int notTake = helper(nums, dp, idx-1, sum);

        int take = 0;

        if(nums[idx] <= sum){
            take = helper(nums, dp, idx-1, sum-nums[idx]);
        }
        
        return dp[idx][sum] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > totalSum){
            return 0;
        }

        if ((totalSum + target) % 2 != 0){
            return 0;
        }
            

        int reqSum = (totalSum + target) / 2;

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(reqSum + 1, -1));

        return helper(nums, dp, n - 1, reqSum);
    }
};