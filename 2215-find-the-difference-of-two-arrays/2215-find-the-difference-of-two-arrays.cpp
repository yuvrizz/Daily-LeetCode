class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> s1(nums1.begin(),nums1.end());
        unordered_set<int> s2(nums2.begin(),nums2.end());

        vector<int> ans1, ans2;

        for(const auto& x : s1){
            if(!s2.contains(x)){
                ans1.push_back(x);
            }
        } 

        for(const auto& y : s2){
            if(!s1.contains(y)){
                ans2.push_back(y);
            }
        }

        return {ans1,ans2};
    }
};