/*
    11. Container With Most Water
    Author: Miguel Angel Bermeo Ayerbe
*/
impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut max_water: i32 = 0;
        let (mut i_left, mut i_right) = (0, height.len().saturating_sub(1));

        while (i_left < i_right){
                max_water = i32::max(max_water,
                                    i32::min(height[i_left],height[i_right])*((i_right-i_left) as i32) );
        
                if height[i_left] < height[i_right] {
                    i_left += 1;
                }else {
                    i_right -= 1;
                }
        }
        return max_water;
    }
}