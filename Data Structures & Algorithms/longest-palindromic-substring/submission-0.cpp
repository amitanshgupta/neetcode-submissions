#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        int start = 0, maxLen = 1;

        for (int i = 0; i < n; i++) {
            // Odd-length palindrome
            pair<int, int> odd = expandAroundCenter(s, i, i);
            if (odd.second > maxLen) {
                start = odd.first;
                maxLen = odd.second;
            }

            // Even-length palindrome
            pair<int, int> even = expandAroundCenter(s, i, i + 1);
            if (even.second > maxLen) {
                start = even.first;
                maxLen = even.second;
            }
        }

        return s.substr(start, maxLen);
    }

private:
    pair<int, int> expandAroundCenter(const string &s, int left, int right) {
        int n = s.size();
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        // (new start index, palindrome length)
        return {left + 1, right - left - 1};
    }
};
