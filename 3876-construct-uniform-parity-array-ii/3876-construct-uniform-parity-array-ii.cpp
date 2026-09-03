class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallest = *min_element(nums1.begin(), nums1.end());
        bool parity = smallest % 2;

        bool ans = 1;

        for(int i=0; i<nums1.size(); i++){
            if(nums1[i] % 2 != parity){
                int diff = nums1[i] - smallest;

                if(diff % 2 != parity){
                    ans = 0;
                }
            }
        }

        return ans;
    }
};