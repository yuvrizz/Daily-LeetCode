class Solution {
public:
    // Same ques as best time to buy and sell stocks.
    int maximumDifference(vector<int>& nums) {
        
        int minimum = nums[0];
        int max_diff = -1; 

        for(int i=0; i<nums.size(); i++){
            if(nums[i] > minimum) {
                max_diff = max(max_diff, nums[i] - minimum);
            }
            else {
                minimum = nums[i];
            }
        }

        return max_diff;
    }
};