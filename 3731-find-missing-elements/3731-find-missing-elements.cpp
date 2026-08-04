class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        unordered_set <int> s;
        vector <int> ans;

        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }

        int min_el = *min_element(nums.begin(),nums.end());
        int max_el = *max_element(nums.begin(),nums.end());

        for(int i=min_el; i<= max_el; i++){
            if(!s.contains(i)){
                ans.push_back(i);
            }
        }

        return ans;
    }
};