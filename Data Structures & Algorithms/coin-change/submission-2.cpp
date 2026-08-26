class Solution {
public:
    int f(int i, int target, vector<int>& coins, vector<vector<int>>& dp){
        if(i == 0){
            if(target % coins[0] == 0)
                return target / coins[0];

            return 1e9;
        }

        if(dp[i][target] != -1)
            return dp[i][target];

        int notTake = f(i - 1, target, coins, dp);

        int take = 1e9;
        if(coins[i] <= target){
            take = 1 + f(i, target - coins[i], coins, dp);
        }

        return dp[i][target] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = f(n - 1, amount, coins, dp);

        return ans >= 1e9 ? -1 : ans;
    }
};