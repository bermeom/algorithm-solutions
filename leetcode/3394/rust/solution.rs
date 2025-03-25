/*
    3394. Check if Grid can be Cut into Sections
    Author: Miguel Angel Bermeo Ayerbe
*/
impl Solution {
    pub fn check_valid_cuts(n: i32, rectangles: Vec<Vec<i32>>) -> bool {
        let mut y_axis: Vec<(i32, i32)> = Vec::with_capacity(rectangles.len());
        let mut x_axis: Vec<(i32, i32)> = Vec::with_capacity(rectangles.len());
        for shape_i in rectangles {
            x_axis.push((shape_i[0], shape_i[2]));
            y_axis.push((shape_i[1], shape_i[3]));
        }
        x_axis.sort();
        y_axis.sort();

        let (mut x_i, mut y_i): (usize, usize) = (0, 0);
        for i in 1..x_axis.len() {
            if x_axis[x_i].0 <= x_axis[i].0 && x_axis[i].0 < x_axis[x_i].1 {
                x_axis[x_i].1 = x_axis[x_i].1.max(x_axis[i].1);
            } else {
                x_i += 1;
                x_axis[x_i].0 = x_axis[i].0;
                x_axis[x_i].1 = x_axis[i].1;
            }

            if y_axis[y_i].0 <= y_axis[i].0 && y_axis[i].0 < y_axis[y_i].1 {
                y_axis[y_i].1 = y_axis[y_i].1.max(y_axis[i].1);
            } else {
                y_i += 1;
                y_axis[y_i].0 = y_axis[i].0;
                y_axis[y_i].1 = y_axis[i].1;
            }
        }
        //x_axis.truncate(x_i+1);
        //y_axis.truncate(y_i+1);
        //x_axis.len() >= 3 || y_axis.len() >= 3

        x_i + 1 >= 3 || y_i + 1 >= 3
    }
}
