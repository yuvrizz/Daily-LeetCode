class Solution {
public:
    int countCommas(int n) {
        if(log10(n) < 3){
            return 0;
        }

        return n-999;
    }
};