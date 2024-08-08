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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        stack<TreeNode*> s1, s2;
        s1.push(root);
        while(!s1.empty() || !s2.empty()) {
            vector<int> ans;
            while(!s1.empty()) {
                auto temp = s1.top();
                s1.pop();
                ans.push_back(temp->val);
                if(temp->left)
                    s2.push(temp->left);
                if(temp->right)
                    s2.push(temp->right);
            }
            if(!ans.empty())
                res.push_back(ans);
            ans.clear();
            while(!s2.empty()) {
                auto temp = s2.top();
                s2.pop();
                ans.push_back(temp->val);
                if(temp->right)
                    s1.push(temp->right);
                if(temp->left)
                    s1.push(temp->left);    
            }
            if(!ans.empty())
                res.push_back(ans);
            ans.clear();
        }
        return res;
    }
};