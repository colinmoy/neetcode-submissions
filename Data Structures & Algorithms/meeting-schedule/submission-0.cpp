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
    bool canAttendMeetings(vector<Interval>& intervals) {
        for (unsigned i = 0; i < intervals.size(); i++) {
            Interval x = intervals[i];
            for (unsigned j = 0; j < intervals.size(); j++) {
                Interval y = intervals[j];
                if (i == j) {
                    continue;
                }
                if (x.start < y.end && x.end > y.start) {
                    return false;
                }
                if (y.start < x.end && y.end > x.start) {
                    return false;
                }
            }
        }
        return true;
    }
};
