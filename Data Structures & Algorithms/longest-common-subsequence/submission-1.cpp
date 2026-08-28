class Solution {
public:
/*
    vector<vector<int>> t;
    int f(int i, int j, string& a, string& b){
        if(i==0 || j==0) return 0;
        if(t[i][j]!=-1) return t[i][j];
        if(a[i-1]==b[j-1]){
            return t[i][j] = 1 + f(i-1, j-1, a, b);
        }else{
            return t[i][j] = max(f(i-1, j, a, b), f(i, j-1, a, b));
        }
        return -1;
    }
    */
    int longestCommonSubsequence(string text1, string text2) {
        //hehe boi
        int m = text1.size(), n= text2.size();
      
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        /*
        for(int i = 0; i<=m; i++){
            for(int j=0; j<=n; j++){
                if(i==0 || j==0) t[i][j]=0;
            }
        }
        */
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(text1[i-1]==text2[j-1]) dp[i][j] = dp[i-1][j-1] +1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
