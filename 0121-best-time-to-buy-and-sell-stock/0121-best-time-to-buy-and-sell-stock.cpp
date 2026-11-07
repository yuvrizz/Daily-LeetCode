class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();

        int min = prices[0];
        int max_profit = 0;

        for(int i=0; i<size; i++){
            if(min > prices[i]){
                min = prices[i];
            }
            else{
                int profit = prices[i]-min;
                if(profit > max_profit){
                    max_profit = profit;
                }
            }
        }
    
        return max_profit;
    }
};