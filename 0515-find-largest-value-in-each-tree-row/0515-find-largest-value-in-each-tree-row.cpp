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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            int maxi = INT_MIN;
            while(size--) {
                TreeNode* temp = q.front();
                q.pop();
                maxi = max(maxi, temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);    
            }
            res.push_back(maxi);
        } 
        return res;   
    }
};