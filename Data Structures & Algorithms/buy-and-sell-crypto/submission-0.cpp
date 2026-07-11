class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost = INT_MAX;
        int profit = INT_MIN;
        int n = prices.size();
        for(int i = 0; i < n; i++) {
            cost = min(cost, prices[i]);
            profit = max(profit, prices[i] - cost);
        }

        return profit;
    }
};
