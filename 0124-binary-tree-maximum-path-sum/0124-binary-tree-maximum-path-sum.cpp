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

   int findMaxUtil(TreeNode* root, int &res) {
        if (root == NULL)
            return 0;
    
        int ls = findMaxUtil(root->left, res);
        int rs = findMaxUtil(root->right, res);

        int maxi = max({root->val, ls + root->val, rs + root->val});
        res = max({res, maxi, root->val + ls + rs});
        return maxi;
    }


//    int maxPathSumUtil(TreeNode* root, int &res) {
//         if(root == NULL)
//             return 0;

//         int leftSum = max(maxPathSumUtil(root->left, res), 0);
//         int rightSum = max(maxPathSumUtil(root->right, res), 0);

//         res = max(res, leftSum + rightSum + root->val);
//         return max(leftSum, rightSum) + root->val;    
//    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        //maxPathSumUtil(root, res);
        findMaxUtil(root, res);
        return res;
    }
};