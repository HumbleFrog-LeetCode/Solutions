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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> ans;
            while(size--) {
                TreeNode *temp = q.front();
                q.pop();
                ans.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);    
            }
            res.push_back(ans);
        }
        return res;
    }
};