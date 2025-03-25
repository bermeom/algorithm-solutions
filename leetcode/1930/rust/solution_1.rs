/*
    1930. Unique Length-3 Palindromic Subsequences
    Author: Miguel Angel Bermeo Ayerbe
*/
impl Solution {
    pub fn count_palindromic_subsequence(s: String) -> i32 {
        let mut middle_marks: [i32; 26] = [0; 26];
        let mut last: [usize; 26] = [0; 26];
        let mut first: [usize; 26] = [0; 26];
        for (i, char_i) in s.chars().enumerate() {
            let char_b_i: usize = ((char_i as u8) - b'a') as usize;
            if 2 <= i {
                if first[char_b_i] != 0 {
                    for i in 0..26 {
                        if last[i] != 0 && first[char_b_i] < last[i] {
                            middle_marks[char_b_i] |= 1 << i;
                        }
                    }
                }
            }
            last[char_b_i] = i + 1;
            if first[char_b_i] == 0 {
                first[char_b_i] = i + 1;
            }
        }
        let mut output: i32 = 0;
        for i in 0..26 {
            if first[i] > 0 {
                for j in 0..26 {
                    output += (middle_marks[i] >> j) & 1;
                }
            }
        }
        output
    }
}
