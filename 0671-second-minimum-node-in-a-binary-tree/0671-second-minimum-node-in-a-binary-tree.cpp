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

    void minimum(TreeNode* root, int &first, int &second, int &flag) {
        if(root == NULL)
            return;

        minimum(root->left, first, second, flag);

        if(root->val == INT_MAX)
            flag = 1;

        if(root->val < first) {
            second = first;
            first = root->val;
        }            
        if(root->val > first && root->val < second)
            second = root->val;
                
        minimum(root->right, first, second, flag);
    }

    int findSecondMinimumValue(TreeNode* root) {
        int first = INT_MAX, second = INT_MAX, flag = 0;
        minimum(root, first, second, flag);
        if(first == second)
            return -1;
        if(second == INT_MAX && first != second && flag == 0)
            return -1;
        return second;    
    }
};