class Solution {
public:
    vector<int> dp;
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;
        int n = s.size();
        dp.assign(n, -1);
        return f(0, s);
    }
    int f(int i, string& s){
        int n = s.size();
        if(i>=n) return 1;
        if(s[i] == '0') return 0;
        if(dp[i]!=-1) return dp[i];
        int cnt = 0;
        cnt += f(i+1, s);
        if(i+1<n &&(s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))) cnt+= f(i+2, s);
        return dp[i] = cnt;
    }
};
