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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = -1;

        while(!q.empty()) {
            int size = q.size();
            level++;
            int decreasing = INT_MAX;
            int increasing = INT_MIN;
            while(size--) {
                TreeNode *temp = q.front();
                q.pop();
                int data = temp->val;
                   
                if(level&1) {
                    if(data >= decreasing || (data & 1))
                        return false;
                    else
                        decreasing = data;
                } 
                else {
                    if(data <= increasing || !(data & 1))
                        return false;
                    else
                        increasing = data;
                }
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);    
            }
        }
        return true; 
    }
};