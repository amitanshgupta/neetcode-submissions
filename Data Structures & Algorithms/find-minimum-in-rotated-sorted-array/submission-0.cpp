class Solution {
public:
    int findMin(vector<int> &nums) {
        //return *min_element(nums.begin(), nums.end());
        int n = nums.size();
        int lo = 0, hi = n-1;
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            //infliction point lies on the right half
            if(nums[mid] > nums[hi]){
                lo = mid + 1;
            }else{
                hi = mid;
            }
        }
        return nums[lo];
    }
};
