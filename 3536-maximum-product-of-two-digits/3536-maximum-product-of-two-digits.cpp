class Solution {
public:
    int maxProduct(int n) {
        
        int x = n; 
        vector<int> temp;

        while(x>0){
            int digit = x % 10; 
            temp.push_back(digit);
            x = x/10;
        }

        sort(temp.begin(),temp.end());

        return temp[temp.size()-1] * temp[temp.size()-2];
    }
};