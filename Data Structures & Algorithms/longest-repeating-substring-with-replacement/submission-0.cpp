class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int n = s.length();

        int i = 0, j = 0;
        int ans = 0, maxFreq = 0;
        while(j<n){
            mp[s[j]]++;
            maxFreq = max(maxFreq, mp[s[j]]);
            if((j-i+1)-maxFreq > k){
                mp[s[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
