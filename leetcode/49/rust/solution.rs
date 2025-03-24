/*
    49. Group Anagrams
    Author: Miguel Angel Bermeo Ayerbe
*/
use std::collections::HashMap;
impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut map: HashMap<[u8; 26], Vec<String>> = HashMap::new();
        for word_i in strs {
            let mut frequency: [u8; 26] = [0; 26];
            for char_i in word_i.chars() {
                frequency[((char_i as u8) - b'a') as usize] += 1;
            }
            map.entry(frequency).or_insert(Vec::new()).push(word_i)
        }
        map.into_values().collect()
    }
}
