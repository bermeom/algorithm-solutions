/*
    12. Integer to Roman
    Author: Miguel Angel Bermeo Ayerbe
*/
impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let roman_map: Vec<(i32, &'static str)> = vec![
            (1000, "M"),
            (900, "CM"),
            (500, "D"),
            (400, "CD"),
            (100, "C"),
            (90, "XC"),
            (50, "L"),
            (40, "XL"),
            (10, "X"),
            (9, "IX"),
            (5, "V"),
            (4, "IV"),
            (1, "I"),
        ];
        let mut roman: String = String::new();
        let mut local_num = num;
        roman.reserve(10);
        for (roman_num, roman_str) in roman_map.iter() {
            while local_num >= *roman_num {
                roman.push_str(*roman_str);
                local_num -= *roman_num;
            }
        }
        roman
    }
}
