// class Solution {
// public:
//     int sumCounts(vector<int>& nums) {
        
//         int ans = 0; 

//         for(int i=0; i<nums.size(); i++){
//             for(int j=i; j<nums.size(); j++){

//                 unordered_set<int> st;

//                 for (int k = i; k <= j; k++){

//                     if(!st.contains(nums[k])){
//                         st.insert(nums[k]);
//                     }

//                 }

//                 int count = st.size();
//                 ans += count * count;
//             }
//         }

//         return ans;
//     }
// };


class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            unordered_set<int> st;

            for (int j = i; j < n; j++) {
                st.insert(nums[j]); 

                int count = st.size();
                ans += count * count;
            }
        }

        return ans;
    }
};