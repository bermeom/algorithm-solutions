/*
    199. Binary Tree Right Side View
    Author: Miguel Angel Bermeo Ayerbe
*/
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;
impl Solution {
    pub fn right_side_view(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut queue: VecDeque<(usize, Rc<RefCell<TreeNode>>)> = VecDeque::new();
        let mut output: Vec<i32> = Vec::new();
        if let Some(root) = root {
            queue.push_back((0, root));
            while !queue.is_empty() {
                let (level, node_i_rc_rcell) = queue.pop_front().unwrap();
                let node_i = node_i_rc_rcell.borrow();
                if level == output.len() {
                    output.push(node_i.val);
                } else {
                    output[level] = node_i.val;
                }
                if let Some(left_node) = &node_i.left {
                    queue.push_back((level + 1, left_node.clone()));
                }
                if let Some(right_node) = &node_i.right {
                    queue.push_back((level + 1, right_node.clone()));
                }
            }
        }
        output
    }
}
