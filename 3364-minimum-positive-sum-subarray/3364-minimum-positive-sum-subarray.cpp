class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        
        int n = nums.size();
        int ans = INT_MAX; 

        for(int i=0; i<=n-l; i++){
            
            int sum = 0;
            int j = i; 

            for(j; j<i+l; j++){
                sum += nums[j];
            }

            if(sum > 0){
                ans = min(ans,sum);
            }
            
            for(j; j < i+r && j<n; j++){
                sum += nums[j];

                if(sum > 0){
                    ans = min(ans,sum);
                }
            }
        }

        if(ans == INT_MAX){
            return -1;
        }

        return ans;
    }
};