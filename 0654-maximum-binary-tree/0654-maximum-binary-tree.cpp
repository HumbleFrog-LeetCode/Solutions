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

    int findMax(vector<int> &nums, int start, int end) {
        int maxi = nums[start], index = start;
        for(int i=start+1; i<=end; i++) {
            if(nums[i] > maxi) {
                maxi = nums[i];
                index = i;
            }
        }
        return index;
    }
    
    TreeNode* build(vector<int> &nums, int start, int end) {
        if(start > end)
            return NULL;
        int index = findMax(nums, start, end);
        TreeNode *root = new TreeNode(nums[index]);
        root->left = build(nums, start, index-1);
        root->right = build(nums, index+1, end);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);   
    }
};