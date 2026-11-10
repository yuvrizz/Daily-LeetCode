class Solution {
    private int help(int i, int[] costs, int[] dp) {

        if (i == 0){
            return 0;
        }

        if (dp[i] != -1){
            return dp[i];
        }

        int one = Integer.MAX_VALUE;
        int two = Integer.MAX_VALUE;
        int three = Integer.MAX_VALUE;

        if (i >= 1){
            one = costs[i - 1] + 1 + help(i-1,costs,dp);
        }
        if (i >= 2){
            two = costs[i - 1] + 4 + help(i-2,costs,dp);
        }
        if (i >= 3){
            three = costs[i - 1] + 9 + help(i-3,costs,dp);
        }

        return dp[i] = Math.min(one, Math.min(two, three));
    }

    public int climbStairs(int n, int[] costs) {

        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);

        return help(n, costs, dp);
    }
}