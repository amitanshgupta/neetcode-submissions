class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> adj(26);
        //indegree map for storing indegree of each char in dictionary
        unordered_map<char, int> inDegree;

        for(auto& word : words){
            for(char c : word){
                inDegree[c] = 0;
            }
        }

        string ans = "";
        bool found = false;
        for(int i = 0; i < n - 1; i++){
            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());

            for(int j = 0; j < len; j++){
                if(s1[j] != s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    inDegree[s2[j]]++; //increase the indegree as connected edges are found
                    found = true;
                    break;
                }
            }
            if(!found && s1.size() > s2.size())
                return "";
        }

        //now apply toposort/ kahn's algo
        queue<char> q;

        for (auto& p : inDegree) {
            if (p.second == 0) {
                q.push(p.first);
            }
        }

        while(!q.empty()){
            char c = q.front();
            q.pop();
            ans.push_back(c);
            for(auto it: adj[c - 'a']){
                inDegree[it+'a']--;
                if(inDegree[it+'a'] == 0){
                    q.push(it+'a');
                }
            }
        }
        if(ans.size()!=inDegree.size()) return "";
        return ans;
    }
};
