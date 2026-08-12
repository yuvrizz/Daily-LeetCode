class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int ptr = 0; 
        int n = nums.size();
        int result = 0; 
        unordered_map<int,int> freq;

        for(int i=0; i<n; i++){
            freq[nums[i]]++;

            while(freq[nums[i]] > k){
                freq[nums[ptr]]--;
                ptr++;
            }

            result = max(result, i-ptr+1);
        }

        return result;
    }
};