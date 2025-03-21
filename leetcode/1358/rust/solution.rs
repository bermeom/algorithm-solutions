/*
    1358. Number of Substrings Containing All Three Characters
    Author: Miguel Angel Bermeo Ayerbe
*/
use std::cmp;

impl Solution {
    pub fn number_of_substrings(s: String) -> i32 {
        let mut marks: Vec<i32> = vec![-1,-1,-1];
        let mut count: i32 = 0;
        let mut i: i32 = 0;
        
        for c_i in s.as_bytes() {
            marks[(c_i - b'a') as usize] = i as i32;
            count += 1+cmp::min(cmp::min(marks[0], marks[1]), marks[2]);
            i+=1;
        }
        count
    }
}