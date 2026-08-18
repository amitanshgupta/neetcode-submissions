class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        unordered_map<char, int> freq;
        for(auto &row: board){
            for(auto c: row){
                freq[c]++;
            }
        }

        for(auto c: word){
            if(--freq[c]<0) return false;
        }

        for(int i = 0; i<n; i++){
            for(int j =0; j<m; j++){
                if(solve(i, j, board, word, 0)) return true;
            }
        }
        return false;
    }
    bool solve(int r, int c, vector<vector<char>>& board, string& word,int k){
        if(k == word.size()) return true;
        int n = board.size();
        int m = board[0].size();
        if(r<0 || r >= n || c<0 || c >= m) return false;

        char state = board[r][c];

        if(board[r][c] != word[k]) return false;
        board[r][c] = '#';

        static int dr[4] = {0, 1, -1, 0};
        static int dc[4] = {1, 0, 0, -1};

        for(int i =0; i<4; i++){
            if(solve(r + dr[i], c + dc[i], board, word, k+1)) return true;;
        }

        board[r][c] = state;
        return false;
    }
};
