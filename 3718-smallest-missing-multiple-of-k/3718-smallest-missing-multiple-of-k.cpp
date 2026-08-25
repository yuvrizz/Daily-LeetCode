class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        unordered_set<int> s;
        int n = nums.size();

        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }

        for(int i=1; i<=n; i++){
            if(!s.contains(k*i)){
                return k*i;
            }
        }

        return k*(n+1);
    }
};