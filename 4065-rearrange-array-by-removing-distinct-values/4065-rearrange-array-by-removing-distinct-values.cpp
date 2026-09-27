class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        map<int,int> mp;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        bool rem = true; 

        while(rem){
            rem = false; 

            for(auto &[x,freq] : mp){
                if(freq > 0){
                    ans.push_back(x);
                    mp[x]--;
                    rem = true;
                }
            }
        }

        return ans; 
    }
};