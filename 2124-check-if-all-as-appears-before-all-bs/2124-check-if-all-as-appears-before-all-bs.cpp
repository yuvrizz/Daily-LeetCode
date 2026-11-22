class Solution {
public:
    bool checkString(string s) {
        
        bool b = false; 

        for(int i=0; i<s.size(); i++){

            if(b && s[i] == 'a'){
                return false;
            }

            if(s[i] == 'b'){
                b = true;
            }
        }

        return true;
    }
};