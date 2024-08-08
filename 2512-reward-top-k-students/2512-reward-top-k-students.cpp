class Solution {
public:

    struct compare {
        bool operator()(pair<int, int> a, pair<int, int> b){
            if(a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;    
        }
    };

    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> positive(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> negative(negative_feedback.begin(), negative_feedback.end());

        unordered_map<int, int> mp; // {student_id, points}
        for(int i=0; i<report.size(); i++) {
            if(mp.find(student_id[i]) == mp.end())
                mp[student_id[i]] = 0;
            istringstream ss(report[i]);
            string word;
            while (ss >> word) {
                if(positive.count(word))
                    mp[student_id[i]] += 3;
                if(negative.count(word))
                    mp[student_id[i]] -= 1;    
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        for(auto x: mp)
            pq.push({x.second, x.first});
        
        vector<int> res;
        while(k-- && !pq.empty()) {
            auto x = pq.top();
            pq.pop();
            res.push_back(x.second);
        }
        return res;
    }
};