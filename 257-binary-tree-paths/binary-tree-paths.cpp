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
    void answer(TreeNode* node, vector<string>& ans, string x) {
        x += to_string(node->val);
        if(node->left) answer(node->left, ans,x + "->");
        if(node->right) answer(node->right, ans,x +"->");
        if (!node->left && !node->right) ans.push_back(x);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        answer(root, ans,"");
        return ans;
    }
};