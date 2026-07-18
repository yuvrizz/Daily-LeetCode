class Solution {
public:
    long long maximumValue(int n, int s, int m) {

        if (n == 1){
            return s;
        }

        long long max_val = n/2;

        return 1LL*s + m + (max_val-1) * (m-1);
    }
};