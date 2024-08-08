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

    string findDuplicateSubs(TreeNode* root, unordered_map<string, int> &mp, vector<TreeNode*> &res) {
        if(root == NULL)
            return "()";

        string left = findDuplicateSubs(root->left, mp, res);
        string right = findDuplicateSubs(root->right, mp, res);

        string str = "(" + to_string(root->val) + left + right + ")";
        mp[str]++;

        if(mp[str] == 2)  
            res.push_back(root);   
        return str;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> mp;
        findDuplicateSubs(root, mp, res);
        return res;
    }
};