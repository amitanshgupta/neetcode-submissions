class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int f(int cur, int prev, vector<int>& nums){
        if(cur == n) return 0;
        //prev+1 because  prev starts with -1 base
        if(dp[cur][prev + 1] != -1)
            return dp[cur][prev + 1];

        // not take
        int len = f(cur + 1, prev, nums);

        // take
        if(prev == -1 || nums[cur] > nums[prev]){
            len = max(len, 1 + f(cur + 1, cur, nums));
        }

        return dp[cur][prev + 1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        dp.assign(n, vector<int>(n + 1, -1));

        return f(0, -1, nums);
    }
};