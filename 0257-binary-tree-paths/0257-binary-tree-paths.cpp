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

    void buildOutput(int a[], int n, vector<string> &res) {
        string s;
        int i;
        for(i = 0; i<n-1; i++) {
            s.append(to_string(a[i]));
            s.append("->");
        }
        s.append(to_string(a[i]));   
        res.push_back(s); 
    }

    void pathUtil(TreeNode* root, int path[], int pathlen, vector<string> &res) {
        if(root == NULL)
            return;
        path[pathlen++] = root->val;
        if(root->left == NULL && root->right == NULL)
            buildOutput(path, pathlen, res);

        pathUtil(root->left, path, pathlen, res);
        pathUtil(root->right, path, pathlen, res);    
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        int path[1000], pathlen = 0;
        if(root == NULL)
            return res;
        pathUtil(root, path, pathlen, res);   
        return res; 
    }
};