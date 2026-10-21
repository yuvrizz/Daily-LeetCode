// class Solution {
// public:
//     vector<int> targetIndices(vector<int>& nums, int target) {
        
//         sort(nums.begin(),nums.end());

//         vector<int> ans;

//         for(int i=0; i<nums.size(); i++){
//             if(nums[i] == target){
//                 ans.push_back(i);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        int smaller = 0;
        int count = 0;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++){

            if(nums[i] < target){
                smaller++;
            }

            if(nums[i] == target){
                count++;
            }
        }

        while(count){
            ans.push_back(smaller++);
            count--;
        }

        return ans;
    }
};