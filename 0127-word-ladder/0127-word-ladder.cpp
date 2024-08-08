class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(beginWord == endWord || !dict.count(endWord))
            return 0;
        queue<string> q;
        q.push(beginWord);
        int level = 0;
        while(!q.empty()) {
            level++;
            int size = q.size();
            while(size--) {
                string word = q.front();
                q.pop();
                for(int i = 0; i < word.length(); i++) {
                    char x = word[i];
                    for(char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;
                        if(word == endWord)
                            return level + 1;
                        if(!dict.count(word))
                            continue;
                        dict.erase(word);
                        q.push(word);        
                    }
                    word[i] = x;
                }
            }
        }    
        return 0;
    }
};