class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char, int> mp;
        for(auto it: t) mp[it]++;

        int count = mp.size();
        int start = 0;
        int ans = INT_MAX; //supposing that substring doesn't exists

        int i = 0, j = 0;

        while(j<n){

            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0) count--;
            }

            while(count == 0){
                if(j-i+1 < ans){
                    ans = j-i+1;
                    start = i;
                }
                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1) count++;
                }
                i++;
            }
            j++;
        }
        if(ans == INT_MAX) return "";
        return s.substr(start, ans);
    }
};
