class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n= intervals.size();
        int i = 0;
        int start = newInterval[0], end = newInterval[1];

        // adding intervals just before the new interval
        while(i<n && intervals[i][1] < start){
            res.push_back(intervals[i]);
            i++;
        }

        //adding the new and merging the overlapping interval
        while(i<n && intervals[i][0] <= end ){
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }

        res.push_back({start, end});

        //adding the remaining intervals
        while(i<n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
