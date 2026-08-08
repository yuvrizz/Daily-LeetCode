class Solution {
public:
    int helper(int idx, vector<int>& coins, int amount, vector<vector<int>>& dp){

        if(amount == 0){
            return 0;
        }

        if(idx == coins.size() || amount < 0){
            return 1e9;
        }

        if(dp[idx][amount] != -1){
            return dp[idx][amount];
        }

        int include = 1e9;

        if(coins[idx] <= amount){
            include = helper(idx,coins,amount-coins[idx],dp);
        }

        int exclude = helper(idx+1,coins,amount,dp);

        dp[idx][amount] = min(1+include, exclude);

        return dp[idx][amount];
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = helper(0, coins, amount, dp);

        if(ans == 1e9){
            return -1;
        }

        return ans;
    }
};