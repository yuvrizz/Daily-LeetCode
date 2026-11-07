class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int maxProfit = 0; 
        int min_el = prices[0];

        for(int i=1; i<prices.size(); i++){
            int profit = prices[i] - min_el;
            maxProfit = max(maxProfit,profit);
            min_el = min(min_el,prices[i]);
        }

        return maxProfit;
    }
};