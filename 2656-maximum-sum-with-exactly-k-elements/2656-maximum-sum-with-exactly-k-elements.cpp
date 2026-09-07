class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int max_el = *max_element(nums.begin(), nums.end());
        return k*(2*max_el+(k-1))/2;
    }
};