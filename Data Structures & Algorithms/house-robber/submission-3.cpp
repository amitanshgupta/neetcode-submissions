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
        vector<int> t(n, 0);
        if(n==0) return 0;
        if(n==1) return nums[0];
        t[0] = nums[0];
        t[1] = max(nums[0], nums[1]);
        for(int i = 2; i<n; i++){
            t[i] = max(t[i-2] + nums[i], t[i-1]);
        }
        return t[n-1];
    }
};
