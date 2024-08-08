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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            int y = t.second.first;
            int x = t.second.second;
            TreeNode* temp = t.first;
            mp[y][x].insert(temp->val);
            if(temp->left)
                q.push({temp->left, {y-1, x+1}});
            if(temp->right)
                q.push({temp->right, {y+1, x+1}}); 
        }   

        for(auto i: mp){
            vector<int> ans;
            for(auto j: i.second)
                for(auto k: j.second)
                    ans.push_back(k);
            res.push_back(ans);    
        } 
        return res;
    }
};