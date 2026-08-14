class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = 0;
        int i = 0, j = heights.size() -1;
        while(i<j){
            int temp = min(heights[i], heights[j]) * (j-i);
            area = max(area, temp);
            if(heights[i] < heights[j]) i++;
            else j--;
        }
        return area;
    }
};
