class Solution {
public:
    // Recursive function to check if strings match the given pattern
    bool isMatchHelper(int i, int j, string& s, string& p) {
        // If both strings are exhausted, it's a match
        if (i < 0 && j < 0) return true;

        // If the pattern is exhausted, no match
        if (j < 0) return false;

        // If the string s is exhausted, check if remaining pattern is due to '*'
        if (i < 0) {
            while (j >= 0) {
                if (p[j] != '*') return false;
                j -= 2;
            }
            return true;
        }

        // Matching characters or '.' in the pattern
        if (s[i] == p[j] || p[j] == '.') {
            return isMatchHelper(i - 1, j - 1, s, p);
        }
        // Handling '*'
        else if (p[j] == '*') {
            // Create a new pattern without the current '*' and its preceding character
            string newPattern = p.substr(0, j - 1);
            char prevChar = p[j - 1];

            // Try different possibilities with '*' (including zero occurrences)
            for (int k = 0; k <= i + 1; k++) {
                int newJ = newPattern.length();
                // Recursively check if the new pattern matches
                if (isMatchHelper(i, newJ - 1, s, newPattern)) return true;
                newPattern += prevChar;
            }
        }
        return false;
    }

    bool isMatch(string s, string p) {
        return isMatchHelper(s.length() - 1, p.length() - 1, s, p);
    }
};