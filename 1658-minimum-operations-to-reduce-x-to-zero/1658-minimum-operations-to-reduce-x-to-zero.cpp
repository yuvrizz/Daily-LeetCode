class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int target = accumulate(nums.begin(), nums.end(), 0) - x;

        if(target < 0){
            return -1;
        }

        int left = 0;
        int maxlen = -1;
        int sum = 0;

        for(int i=0; i<nums.size(); i++){

            sum += nums[i];

            while(sum > target){
                sum -= nums[left];
                left++;
            }

            if(target == sum){
                maxlen = max(maxlen,i-left+1);
            }
        }

        if(maxlen == -1){
            return -1;
        }

        return nums.size() - maxlen;
    }
};