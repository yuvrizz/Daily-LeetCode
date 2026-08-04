class Solution {
public:

    void helper(vector<int>& arr, vector<int> &combination, vector<vector<int>> &ans, int idx, int target){

        if(idx == arr.size() || target < 0){
            return;
        }

        if(target == 0){
            ans.push_back(combination);
            return;
        }

        combination.push_back(arr[idx]);
        helper(arr,combination,ans,idx,target-arr[idx]);
        combination.pop_back();

        helper(arr,combination,ans,idx+1,target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        vector<vector<int>> ans; 
        vector<int> combination; 

        helper(candidates,combination,ans,0,target);

        return ans;
    }
};