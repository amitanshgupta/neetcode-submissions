class Solution {
public:
    
    int solve(int idx, vector<int>& nums, vector<int>& t){
        if(idx < 0) return 0;
        if(idx == 0) return nums[0];
        if(t[idx]!=-1) return t[idx];
        return  t[idx] = max(solve(idx-2, nums, t) + nums[idx], solve(idx-1, nums, t));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, -1);
        if(nums.empty()) return 0;
        return solve(n-1, nums, t);
    }
};
