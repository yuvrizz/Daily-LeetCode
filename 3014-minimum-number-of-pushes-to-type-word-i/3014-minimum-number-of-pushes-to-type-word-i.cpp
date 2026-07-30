class Solution {
public:
    int minimumPushes(string word) {
        
        int n = word.size();

        if(n <= 8){
            return n;
        }

        int div = n/8;
        int rem = n%8;
        int x = ((div)*(div+1))/2;

        return 8*x + (div+1)*rem;
    }
};