class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        unordered_map<char, int> mp;
        
        int i = 0, j = 0;
        while(i<n && j<n){

            mp[s[j]]++;

            while(mp[s[j]] > 1){
                mp[s[i]]--;
                i++;
            }
            j++;
            ans = max(ans, j-i);
        }
        return ans;
    }
};
