// ------------------------------------
// Optimal Memoization approach O(n) 
// TLE because of stack overflow.
// ------------------------------------

// class Solution {
// public:

//     int helper(vector<int>& costs, int idx, int n, vector<int> &dp){

//         if(idx == n){
//             return 0;
//         }

//         if(dp[idx] != -1){
//             return dp[idx];
//         }

//         long long oneStep = INT_MAX;
//         long long twoStep = INT_MAX;
//         long long threeStep = INT_MAX;

//         if(idx+1 <= n){
//             oneStep = (long long) helper(costs,idx+1,n,dp) + costs[idx] + 1;
//         }
//         if(idx+2 <= n){
//             twoStep = (long long) helper(costs,idx+2,n,dp) + costs[idx+1] + 4;
//         }
//         if(idx+3 <= n){
//             threeStep = (long long) helper(costs,idx+3,n,dp) + costs[idx+2] + 9;
//         }   

//         dp[idx] = (int) min({oneStep, twoStep, threeStep});

//         return dp[idx];
//     }

//     int climbStairs(int n, vector<int>& costs) {

//         vector<int> dp (n,-1);

//         return helper(costs,0,n,dp);
//     }
// };

// ------------------------------------
// Tabulation Approach 
// Accepted because of no recursive calls

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        
        vector<int> dp(n+1,0);

        dp[n] = 0; 

        for(int idx = n-1; idx >= 0 ; idx--){

            long long oneStep = INT_MAX;
            long long twoStep = INT_MAX;
            long long threeStep = INT_MAX;

            if(idx+1 <= n){
                oneStep = (long long) dp[idx+1] + costs[idx] + 1;
            }
            if(idx+2 <= n){
                twoStep = (long long) dp[idx+2] + costs[idx+1] + 4;
            }
            if(idx+3 <= n){
                threeStep = (long long) dp[idx+3] + costs[idx+2] + 9;
            }   

            dp[idx] = min({oneStep, twoStep, threeStep});
        }

        return dp[0];
    }
};