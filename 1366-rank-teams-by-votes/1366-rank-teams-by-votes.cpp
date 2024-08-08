class Solution {
public:
    string rankTeams(vector<string>& votes) {
        map<pair<char, int>, int> mp; // key = team, position AND value = votes
        set<char> st;
        vector<char> teams;

        for(auto x: votes) {
            int pos = 1;
            for(auto i: x) {
                if(st.find(i) == st.end()) {
                    teams.push_back(i);
                    st.insert(i);
                }
                mp[{i, pos}]++;
                pos++;
            }
        }

        int n = teams.size();
        sort(teams.begin(), teams.end(), [&mp, &n](char a, char b) {
            for(int i = 1; i <= n; i++)
                if(mp[{a, i}] != mp[{b, i}])
                    return mp[{a, i}] > mp[{b, i}];
            return a < b;
        });

        string res = "";
        for(auto x: teams)
            res += x;
        return res;    
    }
};