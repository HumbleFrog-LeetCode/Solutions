/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int ans = INT_MIN;

    vector<int> solve(TreeNode* root) {
        if(root == NULL)
            return {INT_MAX, INT_MIN, 0};
        vector<int> leftSolve = solve(root->left);
        vector<int> rightSolve = solve(root->right);

        if(leftSolve[1] >= root->val || rightSolve[0] <= root->val)
            return {INT_MIN, INT_MAX, 0};

        int res = leftSolve[2] + rightSolve[2] + root->val;
        ans = max(ans, res);
        return {min(leftSolve[0], root->val), max(rightSolve[1], root->val), res};
    }

    int maxSumBST(TreeNode* root) {
        vector<int> a = solve(root);
        return ans < 0 ? 0 : ans;
    }
};