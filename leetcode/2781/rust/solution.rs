/*
    2781. Length of the Longest Valid Substring
    Author: Miguel Angel Bermeo Ayerbe
*/
use std::collections::HashSet;

impl Solution {
    pub fn longest_valid_substring(word: String, forbidden: Vec<String>) -> i32 {
        let mut forbidden_words: HashSet<String> = HashSet::new();
        let mut max_length: usize = 0;
        for forbidden_word_i in forbidden {
            max_length = usize::max(max_length, forbidden_word_i.len());
            forbidden_words.insert(forbidden_word_i);
        }

        let mut left: usize = word.len();
        let mut right: usize = left;
        let word_bytes = word.as_bytes();
        let mut output: usize = 0;
        while (left > 0) {
            let mut substr_i = String::with_capacity(max_length);
            for i in (left - 1)..usize::min(right, left + max_length - 1) {
                substr_i.push(word_bytes[i] as char);
                if (forbidden_words.contains(&substr_i)) {
                    right = i;
                    break;
                }
            }
            output = usize::max(output, right - left + 1);
            left -= 1;
        }
        output as i32
    }
}
