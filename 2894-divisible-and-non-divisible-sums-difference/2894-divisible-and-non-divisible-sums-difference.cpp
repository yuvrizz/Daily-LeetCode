class Solution {
public:
    int differenceOfSums(int n, int m) {
        
        int divisible_sum = 0;
        int i = 1;
        int x = 0;

        while(i*m <= n){
            x = i*m;
            divisible_sum += x;
            i++;
        }

        int all_sum = n*(n+1)/2;
        int non_div_sum = all_sum - divisible_sum;

        return non_div_sum - divisible_sum;
    }
};