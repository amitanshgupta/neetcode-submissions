class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //for 90 deg clockwise, take transpose then rotate rows

        int n = matrix.size();
        //transpose
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //rotate rows
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
