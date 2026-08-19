/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> mp;

        for(auto& it: intervals){
            mp[it.start]++;
            mp[it.end]--;
        }
        int meetings = 0, res = 0;
        for(auto& [time, val] : mp){
            meetings += val;
            res = max(res, meetings);
        }
        return res;
    }
};
