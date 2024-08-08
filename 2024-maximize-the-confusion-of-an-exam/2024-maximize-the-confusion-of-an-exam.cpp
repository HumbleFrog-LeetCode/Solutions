class Solution {
public:

    int maxUtil(string answerKey, char c, int k) {
        int i = 0, j = 0, N = answerKey.size(), ans = 0, count = 0;
        for(; j<N; j++) {
            count += answerKey[j] == c;
            while(i<=j && count > k) 
                count -= answerKey[i++] == c;
            ans = max(ans, j-i+1);    
        }
        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxUtil(answerKey, 'F', k), maxUtil(answerKey, 'T', k));
    }
};