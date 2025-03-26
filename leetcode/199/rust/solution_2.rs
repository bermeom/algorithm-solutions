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
        let mut queue: VecDeque<(usize, Option<Rc<RefCell<TreeNode>>>)> = VecDeque::new();
        let mut output: Vec<i32> = Vec::new();

        queue.push_back((0, root.clone()));
        while !queue.is_empty() {
            if let Some((level, Some(node_i))) = queue.pop_front() {
                let node_i = node_i.borrow();
                if level == output.len() {
                    output.push(node_i.val);
                } else {
                    output[level] = node_i.val;
                }
                queue.push_back((level + 1, node_i.left.clone()));
                queue.push_back((level + 1, node_i.right.clone()));
            }
        }
        output
    }
}
