class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {

        vector<vector<string>> ans;
        string temp1 = "";
        string temp2 = "";

        for(int i=0; i<s1.size(); i++){

            if(s1[i] != s2[i]){
                temp1 += s1[i];
                temp2 += s2[i];
            }

            if(s1[i] == s2[i] && temp1.size() != 0){
                ans.push_back({temp1,temp2});
                temp1 = "";
                temp2 = "";
            }
        }

        if(temp1.size() != 0){
            ans.push_back({temp1,temp2});
        }

        return ans;
    }
};