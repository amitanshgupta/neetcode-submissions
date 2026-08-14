class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty()) return {{""}};
        if(strs.size() < 2) return {strs}; 
        vector<vector<string>> res;
        int n = strs.size();

        unordered_map<string, vector<string>> mp;
        for(auto it: strs){
            string s = it;
            sort(s.begin(), s.end());
            mp[s].push_back(it);
        }

        for(auto it: mp){
            res.push_back(it.second);
        }
        return res;
    }
};
