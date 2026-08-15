class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        for(int i=0; i<n; i++){
            char c = s[i];
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }else{
                if(st.empty()) return false;
                char top = st.top();
                st.pop();
                if(top == '(' && c != ')') return false;
                if(top == '{' && c != '}') return false;
                if(top == '[' && c != ']') return false;
            }
        }
        return st.empty();
    }
};
