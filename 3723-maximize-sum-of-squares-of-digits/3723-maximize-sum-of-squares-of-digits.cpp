class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        
        string ans = ""; 

        if(sum > 9*num){
            return "";
        }

        for(int i=0; i<num; i++){
            if(sum > 9){
                ans += "9";
                sum -= 9;
            }
            else{
                ans += to_string(sum);
                sum = 0;
            }
        }

        return ans;
    }
};