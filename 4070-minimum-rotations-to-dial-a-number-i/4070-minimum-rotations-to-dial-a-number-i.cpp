class Solution {
public:
    int minRotations(string s) {
        
        int result = 0;
        int initial = 0;
        int rot = 0;

        for(int i=0; i<s.size(); i++){

            int curr = int(s[i])-'0';

            if(abs(curr - initial) <= 5){
                rot = abs(curr - initial);
            }
            else{
                rot = 10 - abs(curr-initial);
            }
            
            result += rot;
            initial = curr;
        }

        return result;
    }
};