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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = INT_MIN;
        while(!q.empty()) {
            int size = q.size();
            int left = 0, right = 0;
            for(long long i=0; i<size; i++) {
                auto node = q.front();
                q.pop();
                TreeNode* temp = node.first;
                unsigned long long x = node.second;
                if(i == 0)
                    left = x;
                if(i == size-1)
                    right = x;
                if(temp->left)
                    q.push({temp->left, 2*x + 1});
                if(temp->right)
                    q.push({temp->right, 2*x + 2});    
            }
            unsigned long long diff = right - left + 1;
            int d = int(diff);
            maxWidth = max(maxWidth, d);
        }  
        return maxWidth;  
    }
};