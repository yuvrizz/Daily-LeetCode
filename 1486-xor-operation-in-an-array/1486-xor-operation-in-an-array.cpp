class Solution {
public:
    int xorOperation(int n, int start) {
        
        int xorAns = start;

        for(int i=1; i<n; i++){
            xorAns ^= (start + 2*i);
        }

        return xorAns;
    }
};