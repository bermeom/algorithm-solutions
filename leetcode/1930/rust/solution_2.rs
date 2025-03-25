/*
    1930. Unique Length-3 Palindromic Subsequences
    Author: Miguel Angel Bermeo Ayerbe
*/
impl Solution {
    pub fn count_palindromic_subsequence(s : String) -> i32 {
        let mut forward_intervals : [(usize, usize); 26] = [(s.len(), 0); 26];
        let mut backward_intervals : [usize; 26] = [0; 26];
        let s = s.as_bytes();
        for
            i in 0..s.len() {
                let char_b_i : usize = (s[i] - b 'a') as usize;
                forward_intervals[char_b_i] .0 =
                    forward_intervals[char_b_i] .0.min(i);
                forward_intervals[char_b_i] .1 = i;
            }
        let mut output : usize = 0;

        for
            i in(0..s.len()).rev() {
                let char_b_i : usize = (s[i] - b 'a') as usize;
                if (forward_intervals[char_b_i] .0 == i &&
                    i < forward_intervals[char_b_i] .1) {
                    let(first, last) = forward_intervals[char_b_i];
                    output +=
                        backward_intervals.iter()
                            .filter(| &&last_backward | first < last_backward &&
                                    last > last_backward)
                            .count();
                }
                backward_intervals[char_b_i] = i;
            }
        output as i32
    }
}