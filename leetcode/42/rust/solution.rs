/*
    42. Trapping Rain Water
    Author: Miguel Angel Bermeo Ayerbe
*/
impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        let (mut left, mut right) = (0, height.len().saturating_sub(1));
        let (mut max_left, mut max_right) = (0,0);
        let mut water: i32 = 0;

        while left < right {
            max_left = i32::max(max_left, height[left]);
            max_right = i32::max(max_right, height[right]);

            if max_left < max_right {
                water += max_left - height[left];
                left+=1;
            }else{
                water += max_right - height[right];
                right-=1;                
            }
        }

        water
    }
}