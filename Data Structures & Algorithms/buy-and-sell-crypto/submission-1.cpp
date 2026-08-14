class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int gain =0;
        int j = 1;
        int minPrice = INT_MAX;
        for(int i=0; i<n && j<n; i++){
            minPrice = min(minPrice, prices[i]);
            profit = prices[j] - minPrice;
            gain = max(gain, profit);
            j++;
        }
        return gain;
    }
};
