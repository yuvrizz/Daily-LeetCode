class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int ans = 0; 
        int prev = 0;

        for(int i=0; i<bank.size(); i++){
            int laser = 0;
            for(int j=0; j<bank[0].size(); j++){
                if(bank[i][j] == '1'){
                    laser++;
                }
            }
            ans += prev * laser;

            if(laser != 0){
                prev = laser; 
            }
        }

        return ans;
    }
};