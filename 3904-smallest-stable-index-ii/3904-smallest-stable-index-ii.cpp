class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        vector<int> max_arr(nums.size(),-1);
        vector<int> min_arr(nums.size(),-1);
        int max_el = INT_MIN;
        int min_el = INT_MAX;

        for(int i=0; i<nums.size(); i++){
            max_el = max(max_el,nums[i]);
            max_arr[i] = max_el;
        }

        for(int i=nums.size()-1; i>=0; i--){
            min_el = min(min_el,nums[i]);
            min_arr[i] = min_el;
        }

        for(int i=0; i<nums.size(); i++){
            if(max_arr[i] - min_arr[i] <= k){
                return i;
            }
        }

        return -1;
    }
};