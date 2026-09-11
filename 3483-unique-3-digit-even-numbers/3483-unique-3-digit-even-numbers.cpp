class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        unordered_map<int,int> freq;

        for(int i=0; i<digits.size(); i++){
            freq[digits[i]]++;
        }

        int i = 100; 
        int count = 0;

        while(i < 1000){
            unordered_map<int,int> temp = freq;
            int x = i;

            bool possible = true;

            while(x > 0){
                int digit = x % 10;
                x /= 10;

                if(temp[digit] == 0) {
                    possible = false;
                    break;
                }

                temp[digit]--;
            }

            if(possible){
                count++;
            }

            i += 2;
        }

        return count;
    }
};