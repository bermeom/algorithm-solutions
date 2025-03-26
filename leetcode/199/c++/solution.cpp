/*
    199. Binary Tree Right Side View
    Author: Miguel Angel Bermeo Ayerbe
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> output;
        std::queue<std::pair<size_t, TreeNode*>> q;
        if (root != nullptr) {
            q.push(std::make_pair(0, root));
            std::pair<size_t, TreeNode*> node_i;
            while (!q.empty()) {
                node_i = q.front();
                q.pop();
                if (node_i.first < output.size()) {
                    output[node_i.first] = node_i.second->val;
                } else {
                    output.push_back(node_i.second->val);
                }
                if (node_i.second->left != nullptr) {
                    q.push(
                        std::make_pair(node_i.first + 1, node_i.second->left));
                }
                if (node_i.second->right != nullptr) {
                    q.push(
                        std::make_pair(node_i.first + 1, node_i.second->right));
                }
            }
        }
        return output;
    }
};