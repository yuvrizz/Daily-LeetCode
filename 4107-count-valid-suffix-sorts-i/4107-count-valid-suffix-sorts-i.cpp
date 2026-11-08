class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {

        int n = nums.size();

        unordered_map <int,int> freq;

        for(int x : nums){
            freq[x]++;
        }

        for(int x : target){
            freq[x]--;

            if(freq[x] < 0){
                return 0;
            }
        }

        int first_mismatch = n;

        for(int i=0; i<n; i++){
            if(nums[i] != target[i]){
                first_mismatch = i;
                break;
            }
        }

        int lastbad = -1;

        for(int i=0; i<n-1; i++){
            if(target[i] < target[i+1]){
                lastbad = i;
            }
        }

        return max(0,min(first_mismatch, n-1) - lastbad);
    }
};