class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        int n = nums.size();
        solve(n-1, target, nums, temp);
        return res;
    }
    void solve(int i, int target, vector<int>& nums, vector<int>& temp){
        if(target == 0 ){
            res.push_back(temp);
            return;
        }
        if(i<0 || target<0) return;

        for(int idx = i; idx>=0; idx--){
            if (nums[idx] <= target) {
                temp.push_back(nums[idx]);

                solve(idx, target - nums[idx], nums, temp);

                temp.pop_back();
            }
        }
    }
};
