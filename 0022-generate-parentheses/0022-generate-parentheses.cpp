class Solution {
public:

    void helper(int open, int close, int n, string s, vector<string> &ans){

        if(s.size() == 2*n){
            ans.push_back(s);
            return;
        } 

        if(open < n){
            s.push_back('(');
            helper(open+1,close,n,s,ans);
            s.pop_back();
        }

        if(close < open){
            s.push_back(')');
            helper(open,close+1,n,s,ans);
            s.pop_back();
        }       

    }

    vector<string> generateParenthesis(int n) {

        string s; 
        vector<string> ans;

        helper(0,0,n,s,ans);

        return ans;  
    }
};