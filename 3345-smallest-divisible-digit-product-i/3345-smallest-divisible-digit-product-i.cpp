class Solution {
public:

    int productDigit(int n){

        if(n == 0){
            return 0;
        }

        int product = 1;

        while(n>0){
            int rem = n%10;
            product = product * rem;
            n = n/10;
        }

        return product;
    }

    int smallestNumber(int n, int t) {
        
        for(int i=0; i<10; i++){
            if(productDigit(n) % t == 0){
                return n;
            }
            else{
                n++;
            }
        }

        return -1;
    }
};