class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int close = 0;
        stack <char> st; 

        for(int i=0; i<s.size(); i++){

            if(s[i] == '('){
                st.push('(');
            }
            
            if(s[i] == ')' && !st.empty()){
                st.pop(); 
            }
            else if (s[i] == ')' && st.empty()){
                close++;
            }
        }

        return st.size() + close;
    }
};