class Solution {
public:

    void dfs(int node, unordered_map<int, list<int>> &adj, vector<bool> &visited, stack<int> &s) {
        visited[node] = true;
        for(auto nbr: adj[node])
            if(!visited[nbr])
                dfs(nbr, adj, visited, s);
        s.push(node);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;
        for(int i = 0; i<prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            if(u == v)
                return {};
            adj[v].push_back(u);
        }

        vector<bool> visited(numCourses, 0);

        stack<int> s;
        for(int i = 0; i<numCourses; i++)
            if(!visited[i])
                dfs(i, adj, visited, s);

        map<int, int> mp;
        int index = 0;
        vector<int> ans;
        while(!s.empty()) {
            mp[s.top()] = index++;
            ans.push_back(s.top());
            s.pop();
        }   

        for(int i = 0; i<numCourses; i++) {
            for(auto nbr: adj[i])
                if(mp[i] > mp[nbr])
                    return {};
        } 
  
        if(numCourses == index)
            return ans;
        else
            return {};           
    }
};