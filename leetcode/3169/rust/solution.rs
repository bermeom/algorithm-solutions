/*
    3169. Count Days Without Meetings
    Author: Miguel Angel Bermeo Ayerbe
*/
impl Solution {
    pub fn count_days(days: i32, meetings: Vec<Vec<i32>>) -> i32 {
        let mut meetings: Vec<(i32, i32)> = meetings.into_iter().map(|v| (v[0], v[1])).collect();
        meetings.sort_unstable_by(|l, r| l.0.cmp(&r.0));
        let mut k = 0;
        let mut free_days: i32 = meetings[0].0 - 1;

        for i in 1..meetings.len() {
            if meetings[i].0 <= meetings[k].1 {
                meetings[k].1 = meetings[k].1.max(meetings[i].1);
            } else {
                free_days += meetings[i].0 - meetings[k].1 - 1;
                k += 1;
                meetings[k] = meetings[i];
            }
        }
        free_days + (days - meetings[k].1)
    }
}
