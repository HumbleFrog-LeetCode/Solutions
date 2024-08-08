class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);
        for(int i=0; i<n; i++) {
            if(leftChild[i] != -1)
                indegree[leftChild[i]]++;
                
            if(rightChild[i] != -1)
                indegree[rightChild[i]]++;
        }

        int root = -1, count = 0;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                root = i;
                count++;
            }
        }
        if(count != 1)
            return false;

        queue<int> q;
        q.push(root);
        vector<int> visited(n, 0);
        while(!q.empty()) {
            int temp = q.front();
            q.pop();
            if(visited[temp] == 1)
                return false;
            else
                visited[temp] = 1;    
            if(leftChild[temp] != -1)
                q.push(leftChild[temp]);
            if(rightChild[temp] != -1)
                q.push(rightChild[temp]);    
        }    
        
        int sum = 0;
        for(auto x : visited)
            if(x == 1)
                sum++;

        return sum == n;
    }
};