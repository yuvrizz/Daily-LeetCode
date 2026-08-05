class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        
        // Player 1 = 0 
        // Player 2 - 1 

        bool flag = false; 
        vector<int> scores(2,0);

        for(int i=0; i<nums.size(); i++){
            if(nums[i] % 2 != 0){ //odd
                flag = !flag; 
            }
            
            if((i+1) % 6 == 0){
                flag = !flag; 
            }
            
            scores[flag] += nums[i];
        }

        return (scores[0]-scores[1]);
    }
};