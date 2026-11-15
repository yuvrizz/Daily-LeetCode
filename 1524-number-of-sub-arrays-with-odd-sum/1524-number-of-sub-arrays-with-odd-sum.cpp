class Solution {
public:

    const int MOD = 1e9 + 7;

    int helper(vector<int>& arr, int idx, int sum, int notTaken, vector<vector<int>> &dp){

        if(notTaken == 1 && sum != 0){
            return 0;
        }

        if(idx == arr.size()){
            return sum % 2;
        }

        int state = 0;

        if(sum == 0){
            state = 0;
        }
        else{
            if(sum % 2 == 1){
                state = 1;
            }
            else{
                state = 2;
            }
        }

        if(dp[idx][state] != -1){
            return dp[idx][state];
        }

        int take = helper(arr,idx+1, sum+arr[idx],0,dp);
        int notTake = helper(arr,idx+1,sum,1,dp);

        dp[idx][state] = ((long long)take + notTake + (sum % 2)) % MOD; 

        return dp[idx][state];
    }

    int numOfSubarrays(vector<int>& arr) {
        vector<vector<int>> dp (arr.size()+1, vector<int>(3,-1));
        return helper(arr,0,0,0,dp);
    }
};