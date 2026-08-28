class Solution {
public:
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
    int longestCommonSubsequence(string text1, string text2) {
        //hehe boi
        if(text1.empty() || text2.empty()) return 0;
        t.assign(text1.length()+1, vector<int>(text2.length()+1, -1));

        return f(text1.length(), text2.length(), text1, text2);
    }
};
