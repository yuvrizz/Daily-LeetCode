class Solution {
public:
    bool canAliceWin(int n) {
        
        bool turn = true; 
        int remove = 10;

        while(n > 0){
            n = n - remove;
            remove--;

            if(n < 0){
                return !turn;
            }

            if(n == 0){
                return turn;
            }

            turn = !turn; 
        }

        return -1;
    }
};