class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = nums[0], minP = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int a = nums[i] * maxP, b = nums[i] * minP;
            maxP = max(nums[i], max(a, b));
            minP = min(nums[i], min(a, b));
            res = max(res, maxP);
        }
        return res;
    }
};