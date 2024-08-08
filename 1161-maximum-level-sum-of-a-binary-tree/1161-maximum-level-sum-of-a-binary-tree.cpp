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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL)
            return 0;

        map<int, long long int> mp;    
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        
        while(!q.empty()) {
            int size = q.size();
            long long int sum = 0;
            level++; 
            while(size--) {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);    
            }
            mp[level] = sum;
        } 

        long long int maxi = mp[mp.size()];
        int res = mp.size();
        for(int i=mp.size()-1; i>=1; i--) {
            if(mp[i] >= maxi) {
                res = i;
                maxi = mp[i];
            }
        }
        return res;  
    }
};