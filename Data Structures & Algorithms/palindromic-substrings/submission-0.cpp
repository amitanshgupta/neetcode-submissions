class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if(n<=1) return 1;
        
        int res = 0;
        for(int i = 0; i<n; i++){
            //odd length
            res+= expandAroundCenter(s, i, i);
            //even length
            res+= expandAroundCenter(s, i, i+1);
        }
        return res;
    }
    int expandAroundCenter(const string &s, int left, int right) {
        int n = s.size();
        int res = 0;
        while (left >= 0 && right < n && s[left] == s[right]) {
            res++;
            left--;
            right++;
        }
        
        return res;
    }
};
