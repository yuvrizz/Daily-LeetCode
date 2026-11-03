class Solution {
public:
    int minMoves(vector<int>& nums) {

        int max_el = *max_element(nums.begin(), nums.end());

        int ans = 0;

        for(int i=0; i<nums.size(); i++){
            ans += (max_el-nums[i]);
        }
       
        return ans;
    }
};