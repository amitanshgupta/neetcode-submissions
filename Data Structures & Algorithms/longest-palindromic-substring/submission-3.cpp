class Solution {
public:
    string longestPalindrome(string s) {
        int resIdx = 0, resLen = 1;
        int n = s.size();
        if (n<=1) return s;
        for(int i = 0; i<n; i++){
            //odd length palindrome
            pair<int, int> odd = expandAroundCenter(s, i, i);
            if(odd.second > resLen){
                resIdx = odd.first;
                resLen = odd.second;
            }
            //even length palindrome
            pair<int, int> even = expandAroundCenter(s, i, i+1);
            if(even.second > resLen){
                resIdx = even.first;
                resLen = even.second;
            }
        }

        return s.substr(resIdx, resLen);
    }
    pair<int, int> expandAroundCenter(string& s,int left,int right){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }
        //returning start index and the length of palindrome found
        return {left+1, right - left -1};
    }
};
