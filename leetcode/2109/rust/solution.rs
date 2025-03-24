/*
    2109. Adding Spaces to a String
    Author: Miguel Angel Bermeo Ayerbe
*/
impl Solution {
    pub fn add_spaces(s: String, spaces: Vec<i32>) -> String {
        let mut output = String::with_capacity(s.len() + spaces.len());
        let mut j: usize = 0;
        for (i, char_i) in s.chars().enumerate() {
            if j < spaces.len() && spaces[j] as usize == i {
                output.push(' ');
                j += 1;
            }
            output.push(char_i);
        }
        output
    }
}
