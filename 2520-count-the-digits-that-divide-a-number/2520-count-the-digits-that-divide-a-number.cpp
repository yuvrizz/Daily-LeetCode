class Solution {
public:
    int countDigits(int num) {
        
        int x = num;
        vector<int> temp;
        int count = 0;

        while(x > 0){
            int rem = x % 10;
            temp.push_back(rem);
            x = x/10;
        }

        for(int i=0; i<temp.size(); i++){
            if(num % temp[i] == 0){
                count++;
            }
        }

        return count;
    }
};