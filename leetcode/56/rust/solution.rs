/*
    56. Merge Intervals
    Author: Miguel Angel Bermeo Ayerbe
*/
impl Solution {
    pub fn merge(intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        if intervals.is_empty() {
            return intervals;
        }
        let mut intervals = intervals.clone();
        intervals.sort();
        let mut j = 0;
        for i in 1..intervals.len() {
            if intervals[j][0] <= intervals[i][0] && intervals[i][0] <= intervals[j][1] {
                intervals[j][1] = intervals[j][1].max(intervals[i][1]);
            } else {
                j += 1;
                intervals[j][0] = intervals[i][0];
                intervals[j][1] = intervals[i][1];
            }
        }
        intervals.truncate(j + 1);
        intervals
    }
}
