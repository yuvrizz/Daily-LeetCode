class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int ptr = 0; 
        int ones = 0; 
        string ans = ""; 

        for(int i=0; i<s.size(); i++){

            if(s[i] == '1'){
                ones++;
            }

            while(ones > k){
                if(s[i] == '1'){
                    ones--;
                }
                ptr++;
            }

            if(ones == k){

                while(s[ptr] == '0'){
                    ptr++;
                }

                string curr = s.substr(ptr,i-ptr+1);

                if(ans == "" || curr.size() < ans.size() || (curr.size() == ans.size() && curr < ans)){
                    ans = curr; 
                }
            }
        }

        return ans; 
    }
};