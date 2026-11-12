class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int ans = 0;
        int increasing = 0;
        int decreasing = 0;


        for(int i=1; i<nums.size(); i++){

            if(nums[i-1] > nums[i]){
                decreasing++;
            }
            else{
                decreasing = 0;
            }

            if(nums[i-1] < nums[i]){
                increasing++;
            }
            else{
                increasing = 0;
            }

            ans = max({ans,increasing, decreasing});
        }

        return ans+1;
    }
};