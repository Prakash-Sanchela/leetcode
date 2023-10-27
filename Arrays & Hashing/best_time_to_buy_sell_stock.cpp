// problem link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int size = prices.size();
        int buy = prices[0];
        int max_profit = 0;

        for (int i = 1; i< size; i++)
        {
            if (buy > prices[i] )
                buy = prices[i];
            else if(prices[i] - buy > max_profit)
                max_profit = prices[i] - buy;
        }   
        return max_profit;
    }
};
