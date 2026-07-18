class Solution {
public:
    string rearrangeString(string s, char x, char y) {

        int count_x = 0;
        int count_y = 0;
        string all_y, all_x, mid; 

        for(int i=0; i<s.size(); i++){
            if(s[i] == x){
                count_x++;
            }
            else if(s[i] == y){
                count_y++;
            }
        }

        if(count_x == 0 || count_y == 0){
            return s;
        }
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == x){
                all_x += s[i];
            }
            else if(s[i] == y){
                all_y += s[i];
            }
            else{
                mid += s[i];
            }
        }

        return all_y + mid + all_x;
    }
};