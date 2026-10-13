class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        vector<int> vec;

        for(int i=0; i<nums.size(); i++){
            vec.push_back(abs(nums[i]));
        }

        sort(vec.begin(),vec.end(), greater <int>());

        int n = vec.size(); 
        long long sum = 0; 

        for(int i=0; i<n; i++){

            long long sq = vec[i] * vec[i]; 

            if(i < (n+1)/2){
                sum += sq;
            }
            else{
                sum -= sq;
            }
        }

        return sum;
    }
};