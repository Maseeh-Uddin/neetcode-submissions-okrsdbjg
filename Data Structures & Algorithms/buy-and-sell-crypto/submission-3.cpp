class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int currmin = prices[0];
        int currmax = prices[0];
        int profit = 0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]>currmax) {
                currmax = prices[i];
                profit = max(profit,currmax-currmin);
            }
            else if(prices[i]<currmin){
                currmin = prices[i];
                currmax = prices[i];

            }
        }
        return profit;
    }
};
