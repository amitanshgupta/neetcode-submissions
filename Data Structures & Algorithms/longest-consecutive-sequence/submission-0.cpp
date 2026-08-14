class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for(auto it : nums) {
            st.insert(it);
        }

        int ans = 0;

        for(auto it : st) {

            // start only if it is the beginning of a sequence
            if(st.find(it - 1) == st.end()) {

                int current = it;
                int cnt = 1;

                while(st.find(current + 1) != st.end()) {
                    current++;
                    cnt++;
                }

                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};