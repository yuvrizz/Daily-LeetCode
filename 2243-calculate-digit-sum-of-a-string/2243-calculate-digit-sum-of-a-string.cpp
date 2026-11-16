class Solution {
public:
    string digitSum(string s, int k) {

        if(s.size() <= k){
            return s;
        }

        string final_ans = "";

        while(s.size() > k){

            int count = 0;
            string ans = "";
            int sum = 0;

            for(int i=0; i<s.size(); i++){

                sum += s[i] - '0';
                count++;

                if(count == k || i == s.size()-1){
                    ans += to_string(sum);
                    count = 0;
                    sum = 0;
                }
            }

            final_ans = ans;
            s = ans;
        }

        return final_ans;
    }
};