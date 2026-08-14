class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(auto it: strs){
            encoded+= to_string(it.size()) + '#' + it;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for(int i = 0; i< s.length();){
            int j = i;

            while(s[j]!='#'){
                j++;
            }
            int len = stoi(s.substr(i, j-i));

            string a = s.substr(j+1, len);

            ans.push_back(a);

            i = j + 1 + len; 
        }
        return ans;
    }
};
